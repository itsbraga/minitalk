/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:41:01 by panther           #+#    #+#             */
/*   Updated: 2023/11/24 17:26:40 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

void	ft_puthex(unsigned int n, const char *format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else
		{
			if (*format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			if (*format == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
		}
	}
}

int	get_hexlen(unsigned int n)
{
	int	nlen;

	nlen = 0;
	while (n != 0)
	{
		nlen++;
		n /= 16;
	}
	return (nlen);
}

int	ft_printhex(unsigned int n, const char *format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(n, format);
	return (get_hexlen(n));
}
