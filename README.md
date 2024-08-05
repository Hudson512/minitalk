Minitalk
Um sistema simples de comunicação cliente-servidor

Instruções do Projeto
Requisitos Gerais
Nomeie seus arquivos executáveis como client e server.
Entregue um Makefile que compile seus arquivos de origem e não deve relinkar.
Utilize sua libft.
Lide completamente com erros; o programa não deve encerrar inesperadamente (falha de segmentação, erro de barramento, liberação dupla, etc.).
O programa não deve ter vazamentos de memória.
Você pode ter uma variável global por programa (uma para o cliente e uma para o servidor), mas deve justificar seu uso.
Funções Permitidas
Para completar a parte obrigatória, você tem permissão para usar as seguintes funções:

write
ft_printf e qualquer equivalente que você codificou
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit
Funções Utilizadas
1. write
A função write em C é usada para escrever dados em um descritor de arquivo.

Biblioteca: <unistd.h>
Protótipo: ssize_t write(int fd, const void *buf, size_t count);
Uso: Escrever dados em um arquivo, enviar dados através de um socket, escrever dados para dispositivos de hardware.
3. signal
A função signal em C é usada para configurar o tratamento de sinais.

Biblioteca: <signal.h>
Protótipo: void (*signal(int signum, void (*handler)(int)))(int);
Uso: Definir funções de tratamento de sinais, permitindo que um programa responda a eventos assíncronos.
4. sigemptyset
A função sigemptyset em C é usada para inicializar um conjunto de sinais para que ele não contenha nenhum sinal.

Biblioteca: <signal.h>
Protótipo: int sigemptyset(sigset_t *set);
Uso: Inicializar um conjunto de sinais a um estado vazio.
5. sigaddset
A função sigaddset em C é usada para adicionar um sinal a um conjunto de sinais.

Biblioteca: <signal.h>
Protótipo: int sigaddset(sigset_t *set, int signum);
Uso: Adicionar sinais a um conjunto de sinais previamente inicializado.
6. sigaction
A função sigaction em C é usada para examinar ou modificar a ação associada a um sinal específico.

Biblioteca: <signal.h>
Protótipo: int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
Estrutura sigaction:
c
Copiar código
struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};
Uso: Definir como o programa deve responder a sinais específicos.
7. kill
A função kill em C é usada para enviar sinais a processos ou grupos de processos.

Biblioteca: <signal.h>
Protótipo: int kill(pid_t pid, int sig);
Uso: Enviar sinais a processos para terminar, interromper ou continuar a execução.
8. getpid
A função getpid em C é usada para obter o PID (Process ID) do processo chamador.

Biblioteca: <unistd.h>
Protótipo: pid_t getpid(void);
Uso: Obter o PID do processo chamador.
11. pause
A função pause em C é usada para fazer com que o processo atual pause sua execução até que receba um sinal.

Biblioteca: <unistd.h>
Protótipo: int pause(void);
Retorno: Retorna -1 e define errno como EINTR quando o processo é interrompido por um sinal.
12. sleep
A função sleep em C é usada para suspender a execução do processo atual por um número específico de segundos.

Biblioteca: <unistd.h>
Protótipo: unsigned int sleep(unsigned int seconds);
Uso: Introduzir uma pausa no programa.
13. usleep
A função usleep em C é usada para suspender a execução do processo atual por um número especificado de microsegundos.

Biblioteca: <unistd.h>
Protótipo: int usleep(useconds_t usec);
Uso: Introduzir uma pausa de precisão maior que sleep.
PID - Process ID
Para ver o PID (Process ID) de um processo em sistemas Unix-like, você pode usar várias ferramentas de linha de comando.

Usando ps
Listar todos os processos:
sh
Copiar código
ps -e
Filtrar por nome de processo:
sh
Copiar código
ps -e | grep bash
Exibir processos em formato detalhado:
sh
Copiar código
ps aux
SIGUSR1 e SIGUSR2
Os sinais SIGUSR1 e SIGUSR2 são fornecidos para que os programas possam implementar sinais personalizados.

Biblioteca: <signal.h>
Definições:
SIGUSR1: Sinal número 10 em muitos sistemas (mas isso pode variar).
SIGUSR2: Sinal número 12 em muitos sistemas (mas isso pode variar).
Uso: Permitir que os aplicativos definam suas próprias condições de sinalização sem interferir nos sinais padrão.
