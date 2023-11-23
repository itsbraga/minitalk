/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:45:29 by panther           #+#    #+#             */
/*   Updated: 2023/11/22 22:56:05 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printnbr(int n)
{
	char	*nbr;
	int		input;

	input = 0;
	nbr = ft_itoa(n);
	input = ft_printstr(nbr);
	free(nbr);
	return (input);
}
