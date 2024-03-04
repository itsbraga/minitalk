/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:37:05 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/04 19:24:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	sig_handler(int sig, siginfo_t *info, void __attribute__((unused))*s)
{
	static int	bit = 0;
	static char	c;
	pid_t		pid;

	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(pid, SIGUSR1);
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
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(YELLOW"Try this instead: ./server\n");
		return (EXIT_FAILURE);
	}
	pid_display();
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (EXIT_SUCCESS);
}
