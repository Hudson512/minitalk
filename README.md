# minitalk
Um sistema simples de comunicação cliente-servidor

-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------
						Instruções do projeto
-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------
• Nomeie seus arquivos executáveis ​​como client e server.
• Você tem que entregar um Makefile que compilará seus arquivos de origem. Ele não deve relinkar.
• Você definitivamente pode usar sua libft.
• Você tem que lidar com erros completamente. De forma alguma seu programa deve encerrar inesperadamente (falha de segmentação, erro de barramento, liberação dupla e assim por diante).
• Seu programa não deve ter vazamentos de memória.
• ​​Você pode ter uma variável global por programa (uma para o cliente e uma para
o servidor), mas você terá que justificar seu uso.
• Para completar a parte obrigatória, você tem permissão para usar as seguintes
funções:

1-write
2-ft_printf and any equivalent YOU coded
3-signal
4-sigemptyset
5-sigaddset
6-sigaction
7-kill
8-getpid
9-malloc
10-free
11-pause
12-sleep
13-usleep
14-exit

1 - write
	A função write em C é usada para escrever dados em um descritor de arquivo. Aqui estão alguns detalhes importantes sobre a função:	
	
	Biblioteca
		A função write está definida na biblioteca <unistd.h>.
	Protótipo
		ssize_t write(int fd, const void *buf, size_t count);
	Funcionamento
		fd: Este é o descritor de arquivo para onde os dados serão escritos. Pode ser um arquivo, um socket, ou até mesmo a saída padrão (stdout).
		buf: Um ponteiro para o buffer de dados que será escrito.
		count: O número de bytes a serem escritos do buffer.
	Retorno
		A função write retorna o número de bytes que foram escritos com sucesso. Se ocorrer um erro, a função retorna -1 e a variável global errno é definida com o código de erro apropriado.
	Para que serve
		A função write é utilizada para realizar operações de escrita em arquivos ou dispositivos. Aqui estão alguns exemplos comuns de uso:
		Escrever dados em um arquivo.
		Enviar dados através de um socket de rede.
		Escrever dados para dispositivos de hardware.

3- signal
	A função signal em C é usada para configurar o tratamento de sinais. Sinais são notificações assíncronas enviadas ao processo para notificá-lo de eventos como interrupções de teclado, terminação de processo, ou erros de hardware.
	
	Biblioteca
		A função signal está definida na biblioteca <signal.h>.
	Protótipo
		void (*signal(int signum, void (*handler)(int)))(int);
	Funcionamento
		signum: O número do sinal a ser manipulado. Exemplos comuns incluem SIGINT (interrupção do teclado, como Ctrl+C), SIGTERM (pedido de terminação), SIGKILL (força a terminação), etc.
		
		handler: Um ponteiro para a função que vai lidar com o sinal. Esta função deve aceitar um único argumento, um inteiro, que será o número do sinal recebido.
	Retorno
		A função signal retorna o manipulador de sinal anterior se tiver sucesso, ou SIG_ERR em caso de erro.
	Para que serve
		A função signal é utilizada para definir funções de tratamento de sinais, permitindo que um programa responda a eventos assíncronos de forma controlada. Por exemplo, pode ser usada para:

		Limpar recursos antes do término do programa.
		Reiniciar uma operação que foi interrompida por um sinal.
		Ignorar certos sinais.

4- sigemptyset
	A função sigemptyset em C é usada para inicializar um conjunto de sinais (sigset_t) para que ele não contenha nenhum sinal. Isso é útil quando você deseja configurar máscaras de sinal, ou conjuntos de sinais para operações de manipulação de sinais.
	
	Biblioteca
		A função sigemptyset está definida na biblioteca <signal.h>.
	Protótipo
		int sigemptyset(sigset_t *set);
	Funcionamento
		set: Um ponteiro para o conjunto de sinais que será inicializado.
	Retorno
		A função retorna 0 se tiver sucesso. Em caso de erro, retorna -1 e define errno com o código de erro apropriado
	Para que serve
		A função sigemptyset é utilizada para inicializar um conjunto de sinais a um estado vazio, ou seja, sem nenhum sinal. Isso é um passo inicial comum ao configurar máscaras de sinal para bloqueio, desbloqueio ou manipulação de sinais.

5- sigaddset
	A função sigaddset em C é usada para adicionar um sinal a um conjunto de sinais (sigset_t). Isso é útil quando você deseja construir uma máscara de sinal que pode ser usada para bloquear ou manipular sinais.

	Biblioteca
		A função sigaddset está definida na biblioteca <signal.h>.
	Protótipo
		int sigaddset(sigset_t *set, int signum);
	Funcionamento
		set: Um ponteiro para o conjunto de sinais ao qual o sinal será adicionado.
		signum: O número do sinal que será adicionado ao conjunto. Exemplos comuns incluem SIGINT, SIGTERM, SIGKILL, etc.
	Retorno
		A função retorna 0 se tiver sucesso. Em caso de erro, retorna -1 e define errno com o código de erro apropriado.
	Para que serve
		A função sigaddset é utilizada para adicionar sinais a um conjunto de sinais previamente inicializado. Isso é parte da configuração de máscaras de sinal para manipulação de sinais.

6- sigaction
	A função sigaction em C é usada para examinar ou modificar a ação associada a um sinal específico. Ela oferece uma interface mais robusta e flexível para manipulação de sinais do que a função signal.

	Biblioteca
		A função sigaction está definida na biblioteca <signal.h>.
	Protótipo
		int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
		Estrutura sigaction
			A estrutura sigaction é usada para especificar a nova ação para o sinal e, opcionalmente, para recuperar a ação antiga.
			struct sigaction 
			{
    			void (*sa_handler)(int);  // Ponteiro para a função de tratamento de sinal
    			void (*sa_sigaction)(int, siginfo_t *, void *);  // Alternativa para tratamento de sinais com informações extras
    			sigset_t sa_mask;         // Conjunto de sinais a serem bloqueados durante a execução do manipulador
   				int sa_flags;             // Flags que modificam o comportamento do sinal
    			void (*sa_restorer)(void); // Obsoleto, não usado geralmente
			};
	Funcionamento
		signum: O número do sinal a ser manipulado.
		act: Um ponteiro para uma estrutura sigaction que especifica a nova ação para o sinal.
		oldact: Um ponteiro para uma estrutura sigaction onde a ação anterior será armazenada, se não for NULL.
	Retorno
		A função retorna 0 se tiver sucesso. Em caso de erro, retorna -1 e define errno com o código de erro apropriado.
	Para que serve
		A função sigaction é utilizada para definir como o programa deve responder a sinais específicos, como interrupções de teclado (Ctrl+C), terminação de processos, e outros eventos assíncronos.

7- kill
	A função kill em C é usada para enviar sinais a processos ou grupos de processos. Esse sinal pode ser usado para terminar um processo, parar sua execução, ou enviar notificações personalizadas.

	Biblioteca
		A função kill está definida na biblioteca <signal.h>.
	Protótipo
		int kill(pid_t pid, int sig);
	Funcionamento
		pid: O identificador do processo ou grupo de processos para o qual o sinal será enviado.
			. Um valor positivo indica o PID do processo ao qual o sinal deve ser enviado.
			. O valor zero indica que o sinal deve ser enviado a todos os processos no grupo de processos do chamador.
			. O valor -1 indica que o sinal deve ser enviado a todos os processos que o chamador tem permissão para enviar sinais.
			. Um valor negativo (diferente de -1) indica que o sinal deve ser enviado a todos os processos cujo GID (Group ID) seja igual ao valor absoluto de pid.
		sig: O sinal a ser enviado. Isso pode ser qualquer sinal definido em <signal.h>, como SIGKILL, SIGTERM, SIGINT, entre outros.
	Retorno
		A função retorna 0 se tiver sucesso. Em caso de erro, retorna -1 e define errno com o código de erro apropriado.
	Para que serve
		A função kill é utilizada principalmente para enviar sinais a processos, o que pode incluir:
			. Terminar um processo (SIGKILL ou SIGTERM).
			. Interromper um processo (SIGSTOP).
			. Continuar a execução de um processo interrompido (SIGCONT).
			. Enviar sinais personalizados para comunicação entre processos.

8- getpid
	A função getpid em C é usada para obter o PID (Process ID) do processo chamador.
	
	Biblioteca
		Esta função está definida na biblioteca <unistd.h>.
	Protótipo
		pid_t getpid(void);
	Funcionamento
		A função getpid não toma nenhum argumento e retorna o PID do processo chamador.

11-pause
	A função pause em C é usada para fazer com que o processo atual pause sua execução até que receba um sinal. Quando um sinal é recebido e o processo tem um manipulador de sinal registrado para esse sinal, o manipulador de sinal é executado. Depois que o manipulador de sinal termina, a função pause retorna.

	Biblioteca
		A função pause está definida na biblioteca <unistd.h>.
	Protótipo
		int pause(void);
	Retorno
		Pause sempre retorna -1 e define errno como EINTR quando o processo é interrompido por um sinal que tem um manipulador de sinal registrado.

12-sleep
	A função sleep em C é usada para suspender a execução do processo atual por um número específico de segundos. Esta função é útil quando você deseja introduzir uma pausa no seu programa, por exemplo, para esperar por um determinado período antes de continuar a execução.

	Biblioteca
		A função sleep está definida na biblioteca <unistd.h>.
	Protótipo
		unsigned int sleep(unsigned int seconds);
	Funcionamento
		seconds: O número de segundos que o processo deve dormir.
	Retorno 
		A função retorna o número de segundos restantes se o sono foi interrompido por um sinal, ou zero se o sono foi completado sem interrupções.

13-usleep
	A função usleep em C é usada para suspender a execução do processo atual por um número especificado de microsegundos. Esta função é útil quando você precisa de uma pausa mais curta e precisa de uma precisão maior do que a oferecida pela função sleep.

	Biblioteca
		A função usleep está definida na biblioteca <unistd.h>.
	Protótipo
		int usleep(useconds_t usec);
	Funcionamento
		usec: O número de microsegundos para suspender a execução do processo.
	Retorno
		A função retorna 0 se a suspensão foi bem-sucedida, ou -1 em caso de erro (com errno definido apropriadamente).
---------------------------------------------------------------------------------------
							PID - PROCESS ID
---------------------------------------------------------------------------------------
Para ver o PID (Process ID) de um processo em sistemas Unix-like, como Linux, você pode usar várias ferramentas de linha de comando. Aqui estão alguns métodos comuns:
1. Usando ps
	O comando ps exibe informações sobre processos em execução. Aqui estão alguns exemplos de como usá-lo:

	Listar todos os processos
		> ps -e
			Este comando lista todos os processos em execução no sistema, mostrando o PID, o terminal associado, o tempo de CPU utilizado e o comando que iniciou o processo.
	Filtrar por nome de processo
		> ps -e | grep bash
			Podemos usar grep para filtrar a saída do ps por um nome de processo específico. Por exemplo, para encontrar o PID de todos os processos chamados bash.
	Exibir processos em formato detalhado
		> ps aux
			Este comando fornece uma visão detalhada de todos os processos, incluindo informações como o usuário proprietário, uso de memória e CPU, tempo de execução, e o comando completo.
