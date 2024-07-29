/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:34:31 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/29 14:15:25 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av) {
    pid_t pid; // Substitua pelo PID do processo de destino

    // Envia o sinal SIGTERM para o processo especificado
    if (ac != 2)
    	return (0);
    pid = atoi(av[1]);
    if (kill(pid, SIGTERM) == -1) {
        perror("kill");
        return 1;
    }

    printf("Signal SIGTERM sent to process %d\n", pid);

    return 0;
}
