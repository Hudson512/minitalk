/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:46:59 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/26 12:52:13 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int signal) {
    printf("Received signal %d\n", signal);
    exit(1);
}

int main() {
    // Configurar handler para o sinal SIGINT (Ctrl+C)
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    // Loop infinito, aguardando sinais
    while (1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}
