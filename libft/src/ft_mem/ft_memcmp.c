/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:28:00 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && ((char *)s1)[i] == ((char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*int	main(void)
{
	char	s1[]="Hello people";
	char	s2[]="Hello world";

	char	s1a[]="Hello world";
	char	s2a[]="Hello worldd";

	char	s1b[]="Salut a tous";
	char	s2b[]="Salut";

	char	s1c[]="M";
	char	s2c[]="";

	char	s1d[]="Il fait beau";
	char	s2d[]="Il fait beau";

	printf("My function: %d\n", ft_memcmp(s1, s2, 7));
	printf("True: %d\n", memcmp(s1, s2, 7));

	printf("My function: %d\n", ft_memcmp(s1a, s2a, 12));
	printf("True: %d\n", memcmp(s1a, s2a, 12));

	printf("My function: %d\n", ft_memcmp(s1b, s2b, 12));
	printf("True: %d\n", memcmp(s1b, s2b, 12));

	printf("My function: %d\n", ft_memcmp(s1c, s2c, 2));
	printf("True: %d\n", memcmp(s1c, s2c, 2));

	printf("My function: %d\n", ft_memcmp(s1d, s2d, 10));
	printf("True: %d\n", memcmp(s1d, s2d, 10));
}*/
