/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_pause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:13:48 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/31 09:15:17 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("\nCaught signal %d, exiting now.\n", sig);
    exit(0);
}

int main() {
    // Configura o manipulador de sinal para SIGINT
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Mensagem indicando que o programa está aguardando sinais
    printf("Waiting for SIGINT (Ctrl+C)...\n");

    // Pausa a execução até que um sinal seja recebido
    pause();

    // Esta linha nunca será alcançada se o processo for terminado pelo sinal
    printf("This line will not be printed.\n");

    return 0;
}
