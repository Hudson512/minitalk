/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:23:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/31 09:24:47 by hmateque         ###   ########.fr       */
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

    // Loop que dorme por 1 segundo em cada iteração
    while (1) {
        printf("Sleeping for 1 second...\n");
        sleep(1);
    }

    return 0;
}
