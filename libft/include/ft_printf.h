/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:34:12 by panther           #+#    #+#             */
/*   Updated: 2023/11/24 18:26:55 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                                                                            */
/*      Attention! Pour permettre de trouver les paramètres sur la pile       */
/*      d'exécution, il est nécessaire de connaitre au moins un paramètre     */
/*      de la fonction. C'est grace à ce paramètre, qu'une variable de        */
/*      type va_list pourra être initialisée.                                 */
/*                                                                            */
/* ************************************************************************** */
/*
        va_list est une struct contenant :
            - va_argv  :  Permet l'extraction du prochain paramètre passé
                          à la fonction

            - va_copy  :  Permet la copie de la liste d'arguments

            - va_end   :  Permet la libération des ressources acquises pour
                          le parcourt de la liste d'arguments.

            - va_start :  Initialise d'une structure va_list à partir d'un
                          paramètre de la liste.
                                                                             */
int		ft_printf(const char *format, ...);

int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printptr(void *ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned_int(unsigned int n);
int		ft_printhex(unsigned int n, const char *format);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif
