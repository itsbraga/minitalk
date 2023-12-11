/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:37:05 by art3mis           #+#    #+#             */
/*   Updated: 2023/12/11 21:53:14 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
        kill(pid, SIGUSR2);
	}
}

void	pid_display(pid_t pid)
{
	ft_putstr_color_fd(BLUE, "PID ->	", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_color_fd(PURPLE, "Waiting for a message...\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;
	
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(RESET YELLOW"Try this instead: ./server\n");
		return (0);
	}
	pid = getpid();
	pid_display(pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}