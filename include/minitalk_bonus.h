/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:19:09 by art3mis           #+#    #+#             */
/*   Updated: 2023/12/14 23:49:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

/* FUNCTION LIBRAIRIES
 * 
 * signal.h ----> signal, sigemptyset, sigaddset, sigaction, kill
 * stdlib.h ----> exit
 * unistd.h ----> pause, usleep
 * sys/types.h -> getpid
 * 
*/

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

void	confirm_receipt(int signal);
void	send_bits(pid_t pid, char c);
void	send_message(pid_t pid, char *msg);
void	sig_handler(int sig, siginfo_t *info, void __attribute__((unused))*s);
// void	sig_handler(int sig, siginfo_t *info, void *context);
void	pid_display(void);

#endif
