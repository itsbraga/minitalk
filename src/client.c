/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:52:25 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/14 15:23:15 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
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
	send_bits(pid, '\n');
	send_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int	i;

	i = 0;
	if (argc == 3 && ft_strisnum(argv[1]) && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
			send_message(pid, argv[2]);
		else
			ft_printf(BOLD RED"Wrong PID!\n");
	}
	else
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW
			"Try this instead: ./client <SERVER_PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
