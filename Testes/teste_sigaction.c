/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_sigaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:16:27 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/29 11:33:27 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("Caught signal %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;

    // Configura a ação do sinal
    sa.sa_handler = handle_sigint; // Define o manipulador de sinal
    sigemptyset(&sa.sa_mask);      // Inicializa a máscara de sinais
    sa.sa_flags = 0;               // Nenhuma flag adicional

    // Configura a ação para SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Loop infinito aguardando sinais
    while (1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}

/*
Quando o Manipulador é Chamado
A função handle_sigint será chamada automaticamente pelo sistema quando o processo receber o sinal SIGINT. Esse sinal é geralmente gerado quando o usuário pressiona Ctrl+C no terminal. Quando isso acontece:

O processo recebe o sinal SIGINT.
O sistema verifica se há um manipulador registrado para SIGINT.
Encontrando handle_sigint registrado, o sistema chama essa função.
A função handle_sigint executa, imprimindo a mensagem "Caught signal <número do sinal>" e então encerrando o programa com exit(0).
*/
