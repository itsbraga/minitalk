/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:32 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/14 20:26:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal)
{
	static int	bit;
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
	ft_printf(BOLD PURPLE"%d\n", getpid());
	ft_putstr_color_fd(PINK, "Pending...\n", 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW"Try this instead: ./server\n");
		return (0);
	}
	pid_display();
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
