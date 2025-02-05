/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:36:33 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/05 11:22:01 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	receive_pid(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char c;

	(void)context;
	i++;
	c = c << 1;
	if (signal == SIGUSR1)
		c = c | 1;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("Client error: PID NO FOUND\n");
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_sigaction = receive_pid;
	s.sa_flags = SA_SIGINFO;
	sigemptyset(&s.sa_mask);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	ft_printf("My Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}