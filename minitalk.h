/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:29:19 by panther           #+#    #+#             */
/*   Updated: 2023/11/15 20:39:45 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_atoi(const char *str);
void    ft_putstr(char *str);
void    ft_putchar(char c);
void    ft_putnbr(int n);

#endif