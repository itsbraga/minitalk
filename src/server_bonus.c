/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:37:05 by art3mis           #+#    #+#             */
/*   Updated: 2023/12/13 21:44:23 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	sigusr_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;
	pid_t		pid;

	(void)context;
	pid = 0;
	if (info->si_pid)
		pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
	kill(pid, SIGUSR2);
}

void	pid_display(void)
{
	ft_putstr_color_fd(BOLD PURPLE, "PID ->	", 1);
	ft_printf(BOLD PURPLE"%d", getpid());
	ft_putchar_fd('\n', 1);
	ft_putstr_color_fd(PINK, "Pending...\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW"Try this instead: ./server\n");
		return (0);
	}
	pid_display();
	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
