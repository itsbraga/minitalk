/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:23:31 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction efface la data de n bytes en mettant à 0
	(octets contenant « \0 ») les n premiers octets du bloc
	pointé par s.

	Valeur de retour:
	Aucune.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s && !n)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

/*int	main(void)
{
	char	s[50];

	puts("Target:");
	strcpy(s, "J'adore les sushis.");
	puts(s);
	puts("\n");

	puts("My function:");
	ft_bzero(s, 2);
	puts(s);
	puts("\n");

	puts("Computer's function:");
	bzero(s, 2);
	puts(s);
}*/
