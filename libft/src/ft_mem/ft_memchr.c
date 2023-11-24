/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:36:41 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s && !n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if ((char)c == ((char *)s)[i])
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[]="Roses are red, violets are blue.";
	const char	c = 'i';
	char		*ret1;
	char		*ret2;

	ret1 = ft_memchr(s, c, 32);
	ret2 = memchr(s, c, 32);

	puts("memBlock: Roses are red, violets are blue.\n");
	printf("searchedChar: |%c|\nMy function: %s\n", c, ret1);
	printf("searchedChar: |%c|\nTrue: %s\n", c, ret2);
}*/
