/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:32 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/04 19:06:31 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal)
{
	static int	bit = 0;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

void	pid_display(void)
{
	ft_putstr_color_fd(BOLD PURPLE, "PID ->	", 1);
	ft_printf(BOLD PURPLE"%d\n\n", getpid());
	ft_putstr_color_fd(PINK, "Pending...\n", 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW"Try this instead: ./server\n");
		return (EXIT_FAILURE);
	}
	pid_display();
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (EXIT_SUCCESS);
}
