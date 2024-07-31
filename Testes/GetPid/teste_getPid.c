/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_getPid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:16:54 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/29 17:47:36 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigterm(int sig) {
	static int i = 0;
    printf("Caught signal %d, terminating process.\n", sig);
    i++;
    if (i == 5)
    	exit(0);
}

int main() {
    // Configura o manipulador de sinal para SIGTERM
    struct sigaction sa;
    sa.sa_handler = handle_sigterm;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Obtém o PID do processo atual
    printf("\n--------------------------------------\n");
    pid_t pid = getpid();
    printf("	Current process ID: %d", pid);
    printf("\n--------------------------------------\n");

    // Envia o sinal SIGTERM para o próprio processo
    if (kill(pid, SIGINT) == -1) {
        perror("kill");
        return 1;
    }

    // Loop infinito aguardando sinais
    while (1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}

