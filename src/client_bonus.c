/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:46:47 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/04 19:26:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	confirm_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf(GREEN"Server has received a message!\n");
	exit(0);
}

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

void	send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_bits(pid, msg[i]);
		i++;
	}
	send_bits(pid, ' ');
	send_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i = 2;

	if (argc <= 2)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW
			"Try this instead: ./client <SERVER_PID> <MESSAGE>\n");
		return (EXIT_FAILURE);
	}
	while (i < argc && ft_strisnum(argv[1]) && argv[i][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			signal(SIGUSR1, confirm_receipt);
			send_message(pid, argv[i++]);
		}
		else
			ft_printf(BOLD RED"Wrong PID!\n");
	}
	send_bits(pid, '\n');
	return (EXIT_SUCCESS);
}
