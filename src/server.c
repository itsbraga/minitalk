/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:32 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/11 22:13:13 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal)
{
	static int	bit; // pour vérifier combien de bits ont été reçus
	static char	c; // pour stocker la valeur du caractère

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8) // Si bits = 8, on imprime le caractère stocké et on initialise la variable statique.
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
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
	pid_t	pid;
	
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED"Error: invalid arguments.\n");
		ft_printf(RESET YELLOW"Try this instead: ./server\n");
		return (0);
	}
	pid = getpid();
	pid_display(pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (argc == 1)
		pause();
	return (0);
}