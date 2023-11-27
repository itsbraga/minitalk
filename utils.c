/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:03:21 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/27 15:38:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

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
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
	ft_putchar(str[i++]);
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