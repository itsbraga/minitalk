/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:15 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/20 18:09:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // write, pause, sleep, usleep
#include <sys/types.h> // getpid

int     ft_atoi(const char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int n);

#endif