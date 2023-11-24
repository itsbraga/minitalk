/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:45:29 by panther           #+#    #+#             */
/*   Updated: 2023/11/24 17:27:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

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
