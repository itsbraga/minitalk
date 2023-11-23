/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:15 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 03:13:11 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // write, pause, sleep, usleep
#include "Libft/includes/libft.h"

#include <sys/types.h> // getpid


int     ft_atoi(const char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int n);

#endif