/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_sigemptyset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:17:28 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/26 13:22:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t set;

    // Inicializa o conjunto de sinais para estar vazio
    if (sigemptyset(&set) == -1) {
        perror("sigemptyset");
        return 1;
    }

    // Adiciona SIGINT ao conjunto de sinais
    if (sigaddset(&set, SIGINT) == -1) {
        perror("sigaddset");
        return 1;
    }

    // Verifica se o conjunto está realmente vazio
    if (sigismember(&set, SIGINT) == 1) {
        printf("SIGINT is in the set\n");
    } else {
        printf("SIGINT is not in the set\n");
    }

    return 0;
}
