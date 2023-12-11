/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:19:09 by art3mis           #+#    #+#             */
/*   Updated: 2023/12/11 21:51:53 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
#include <stdlib.h> // exit
#include <unistd.h> // pause, usleep
#include <sys/types.h> // getpid

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void    confirm_receipt(int signal);
void    send_bits(pid_t pid, char c);
void	send_message(pid_t pid, char *msg);
void	sigusr_handler(int signal, siginfo_t *info, void *context);
void    pid_display(pid_t pid);

#endif