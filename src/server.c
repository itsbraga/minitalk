/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:32 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 20:04:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/* Function called in response to receiving one of SIGUSR1, SIGUSR2 signals */

void	handler_sigusr(int signal);

int	main(int argc, char **argv)
{
	int	pid;
	
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\nRESET");
		ft_printf(YELLOW"Try this format: ./server\nRESET");
		return (0);
	}
	pid = getpid();
	while (1)
	{
		signal(SIGUSR1, handler_sigusr);
		signal(SIGUSR2, handler_sigusr);
		pause ();
	}
	return (0);
}