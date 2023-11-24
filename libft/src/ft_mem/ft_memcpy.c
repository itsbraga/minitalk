/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:30:57 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((unsigned char *)dest);
}

/*int		main(void)
{
	void	*dest = NULL;
	unsigned char	src[] = "Le 4 mai est le 124e jour de l'annee";
//	unsigned char	*ret1 = ft_memcpy(dest, src, 10);
//	unsigned char	*ret2 = memcpy(dest, src, 24);

	dest = malloc(sizeof(*dest) * 30);
	if (!dest)
		return (0);
	dest = memset(dest, 'j', 30);
	printf("My function: %s\n", (char *)ft_memcpy(dest, src, 10));
//	printf("True: %s\n", ret2);
}*/
