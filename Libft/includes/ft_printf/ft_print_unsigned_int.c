/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:44:08 by panther           #+#    #+#             */
/*   Updated: 2023/11/22 22:55:43 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_digit(long n)
{
	int	len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*nbr;
	int		len_d;

	len_d = len_digit(n);
	nbr = (char *)malloc(sizeof(*nbr) * (len_d + 1));
	if (!nbr)
		return (NULL);
	nbr[len_d] = '\0';
	while (n != 0)
	{
		nbr[--len_d] = n % 10 + 48;
		n /= 10;
	}
	return (nbr);
}

int	ft_print_unsigned_int(unsigned int n)
{
	char	*nbr;
	int		input;

	input = 0;
	if (n == 0)
		input += write(1, "0", 1);
	else
	{
		nbr = ft_utoa(n);
		input += ft_printstr(nbr);
		free(nbr);
	}
	return (input);
}
