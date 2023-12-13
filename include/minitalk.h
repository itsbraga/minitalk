/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:15 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/13 21:17:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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

void	send_bits(pid_t pid, char c);
void	send_message(pid_t pid, char *msg);
void	handler(int signal);
void	pid_display(void);

#endif
