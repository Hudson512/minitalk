/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_siguser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:12:13 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/31 12:11:45 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Manipulador para SIGUSR1
void handle_sigusr1(int sig) {
    printf("Received SIGUSR1 (%d)\n", sig);
}

// Manipulador para SIGUSR2
void handle_sigusr2(int sig) {
    printf("Received SIGUSR2 (%d)\n", sig);
}

int main() {
    // Configura o manipulador de sinal para SIGUSR1
    struct sigaction sa1;
    sa1.sa_handler = handle_sigusr1;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa1, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Configura o manipulador de sinal para SIGUSR2
    struct sigaction sa2;
    sa2.sa_handler = handle_sigusr2;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    if (sigaction(SIGUSR2, &sa2, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Process ID: %d\n", getpid());
    printf("Send SIGUSR1 or SIGUSR2 to this process using `kill -USR1 %d` or `kill -USR2 %d`\n", getpid(), getpid());

    // Loop infinito aguardando sinais
    while (1) {
        pause(); // Aguarda por qualquer sinal
    }

    return 0;
}
