
 <h1>Minitalk</h1>
    <p>Um sistema simples de comunicação cliente-servidor</p>
    <h2>Instruções do Projeto</h2>

<h3>Requisitos Gerais</h3>
    <ul>
        <li>Nomeie seus arquivos executáveis como <code>client</code> e <code>server</code>.</li>
        <li>Entregue um Makefile que compile seus arquivos de origem e não deve relinkar.</li>
        <li>Utilize sua <code>libft</code>.</li>
        <li>Lide completamente com erros; o programa não deve encerrar inesperadamente (falha de segmentação, erro de barramento, liberação dupla, etc.).</li>
        <li>O programa não deve ter vazamentos de memória.</li>
        <li>Você pode ter uma variável global por programa (uma para o cliente e uma para o servidor), mas deve justificar seu uso.</li>
    </ul>

<h3>Funções Permitidas</h3>
    <p>Para completar a parte obrigatória, você tem permissão para usar as seguintes funções:</p>
    <ol>
        <li><code>write</code></li>
        <li><code>ft_printf</code> e qualquer equivalente que você codificou</li>
        <li><code>signal</code></li>
        <li><code>sigemptyset</code></li>
        <li><code>sigaddset</code></li>
        <li><code>sigaction</code></li>
        <li><code>kill</code></li>
        <li><code>getpid</code></li>
        <li><code>malloc</code></li>
        <li><code>free</code></li>
        <li><code>pause</code></li>
        <li><code>sleep</code></li>
        <li><code>usleep</code></li>
        <li><code>exit</code></li>
    </ol>

<h2>Funções Utilizadas</h2>

<h3>1. <code>write</code></h3>
    <p>A função <code>write</code> em C é usada para escrever dados em um descritor de arquivo.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;unistd.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>ssize_t write(int fd, const void *buf, size_t count);</code></li>
        <li><strong>Uso</strong>: Escrever dados em um arquivo, enviar dados através de um socket, escrever dados para dispositivos de hardware.</li>
    </ul>

<h3>3. <code>signal</code></h3>
    <p>A função <code>signal</code> em C é usada para configurar o tratamento de sinais.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>void (*signal(int signum, void (*handler)(int)))(int);</code></li>
        <li><strong>Uso</strong>: Definir funções de tratamento de sinais, permitindo que um programa responda a eventos assíncronos.</li>
    </ul>

<h3>4. <code>sigemptyset</code></h3>
    <p>A função <code>sigemptyset</code> em C é usada para inicializar um conjunto de sinais para que ele não contenha nenhum sinal.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int sigemptyset(sigset_t *set);</code></li>
        <li><strong>Uso</strong>: Inicializar um conjunto de sinais a um estado vazio.</li>
    </ul>

<h3>5. <code>sigaddset</code></h3>
    <p>A função <code>sigaddset</code> em C é usada para adicionar um sinal a um conjunto de sinais.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int sigaddset(sigset_t *set, int signum);</code></li>
        <li><strong>Uso</strong>: Adicionar sinais a um conjunto de sinais previamente inicializado.</li>
    </ul>

<h3>6. <code>sigaction</code></h3>
    <p>A função <code>sigaction</code> em C é usada para examinar ou modificar a ação associada a um sinal específico.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);</code></li>
        <li><strong>Estrutura <code>sigaction</code></strong>:
            <pre><code>struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};</code></pre>
        </li>
        <li><strong>Uso</strong>: Definir como o programa deve responder a sinais específicos.</li>
    </ul>

<h3>7. <code>kill</code></h3>
    <p>A função <code>kill</code> em C é usada para enviar sinais a processos ou grupos de processos.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int kill(pid_t pid, int sig);</code></li>
        <li><strong>Uso</strong>: Enviar sinais a processos para terminar, interromper ou continuar a execução.</li>
    </ul>

<h3>8. <code>getpid</code></h3>
    <p>A função <code>getpid</code> em C é usada para obter o PID (Process ID) do processo chamador.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;unistd.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>pid_t getpid(void);</code></li>
        <li><strong>Uso</strong>: Obter o PID do processo chamador.</li>
    </ul>

<h3>11. <code>pause</code></h3>
    <p>A função <code>pause</code> em C é usada para fazer com que o processo atual pause sua execução até que receba um sinal.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;unistd.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int pause(void);</code></li>
        <li><strong>Retorno</strong>: Retorna -1 e define <code>errno</code> como <code>EINTR</code> quando o processo é interrompido por um sinal.</li>
    </ul>

<h3>12. <code>sleep</code></h3>
    <p>A função <code>sleep</code> em C é usada para suspender a execução do processo atual por um número específico de segundos.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;unistd.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>unsigned int sleep(unsigned int seconds);</code></li>
        <li><strong>Uso</strong>: Introduzir uma pausa no programa.</li>
    </ul>

<h3>13. <code>usleep</code></h3>
    <p>A função <code>usleep</code> em C é usada para suspender a execução do processo atual por um número especificado de microsegundos.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;unistd.h&gt;</code></li>
        <li><strong>Protótipo</strong>: <code>int usleep(useconds_t usec);</code></li>
        <li><strong>Uso</strong>: Introduzir uma pausa de precisão maior que <code>sleep</code>.</li>
    </ul>

<h2>PID - Process ID</h2>
    <p>Para ver o PID (Process ID) de um processo em sistemas Unix-like, você pode usar várias ferramentas de linha de comando.</p>

<h3>Usando <code>ps</code></h3>
    <ul>
        <li><strong>Listar todos os processos</strong>:
            <pre><code>ps -e</code></pre>
        </li>
        <li><strong>Filtrar por nome de processo</strong>:
            <pre><code>ps -e | grep bash</code></pre>
        </li>
        <li><strong>Exibir processos em formato detalhado</strong>:
            <pre><code>ps aux</code></pre>
        </li>
    </ul>

<h2>SIGUSR1 e SIGUSR2</h2>
    <p>Os sinais <code>SIGUSR1</code> e <code>SIGUSR2</code> são fornecidos para que os programas possam implementar sinais personalizados.</p>
    <ul>
        <li><strong>Biblioteca</strong>: <code>&lt;signal.h&gt;</code></li>
        <li><strong>Definições</strong>:
            <ul>
                <li><code>SIGUSR1</code>: Sinal número 10 em muitos sistemas (mas isso pode variar).</li>
                <li><code>SIGUSR2</code>: Sinal número 12 em muitos sistemas (mas isso pode variar).</li>
            </ul>
        </li>
        <li><strong>Uso</strong>: Permitir que os aplicativos definam suas próprias condições de sinalização sem interferir nos sinais padrão.</li>
    </ul>
