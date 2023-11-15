/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:15:17 by panther           #+#    #+#             */
/*   Updated: 2023/11/15 20:38:35 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int     ft_atoi(const char *str)
{
    int     i;
    int     sign;
    int     res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        write(1, str[i], 1);
        i++;
    }
}
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    long    nb;

    nb = n;
    if (nb < 0)
    {
        nb = -nb;
        ft_putchar("-");
    }
    if (nb >= 10)
    {
        ft_putchar(nb / 10);
        ft_putchar(nb % 10);
    }
    else
        ft_putchar(nb + 48);
}