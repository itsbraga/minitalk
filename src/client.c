/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:52:25 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 20:05:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3 && ft_strisnum(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			send_bits(pid, argv[2][i++]);
	}
	else
	{
		ft_printf(RED"Error: invalid arguments.\nRESET");
		ft_printf(YELLOW
		"Try this format: ./client <pid> <message>\nRESET");
		return (1);
	}
	return (0);
}