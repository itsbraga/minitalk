/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:15 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/05 19:39:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // write, pause, sleep, usleep
#include <sys/types.h> // getpid

#include "../libft/include/libft.h" // bonus part
#include "../libft/include/ft_printf.h" // bonus part


void	send_bits(int pid, char c);

#endif