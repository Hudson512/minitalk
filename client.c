/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:58:19 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/05 11:21:44 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	g_response;

void	await_reponse(int bit)
{
	(void)bit;
	g_response = 1;
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			exit(1);
		i++;
	}
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}

void	send_sinal(int pid, char c)
{
	int	count;

	count = 8;
	while (count--)
	{
		if (c >> count & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("CLIENT ERROR: PID NO FOUND\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("CLIENT ERROR: PID NO FOUND\n");
				exit(1);
			}	
		}
		while(g_response == 0 || usleep(50))
			;
		g_response = 0;
	}
}

int	main(int argc, char **agv)
{
	int	i;
	
	i = -1;
	if (argc == 3)
	{
		signal(SIGUSR1, &await_reponse);
		while (agv[2][++i])
			send_sinal(ft_atoi(agv[1]), agv[2][i]);
		send_sinal(atoi(agv[1]), '\0');
	}
	else
		ft_printf("Error ARGUMENT: ./client <PID> <argument>\n");
	return (0);
}