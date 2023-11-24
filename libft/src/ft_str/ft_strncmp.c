/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:51:57 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < n && s1[i] == s2[i])
		i++;
	if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(void)
{
	const char	s1[]="Hello people";
	const char	s2[]="Hello world";
	const char	s3[]="Hello world";
	const char	s4[]="Hello worldd";
	const char	s5[]="Salut a tous";
	const char	s6[]="Salut";
	const char	s7[]="";
	const char	s8[]="N";
	const char	s9[]="Je suis fort";
	const char	s10[]="Je suis fort";

	printf("%d\n", ft_strncmp(s1, s2, 7));
	printf("%d\n", strncmp(s1, s2, 7));
	printf("%d\n", ft_strncmp(s3, s4, 12));
	printf("%d\n", strncmp(s3, s4, 12));
	printf("%d\n", ft_strncmp(s5, s6, 12));
	printf("%d\n", strncmp(s5, s6, 12));
	printf("%d\n", ft_strncmp(s7, s8, 2));
	printf("%d\n", strncmp(s7, s8, 2));
	printf("%d\n", ft_strncmp(s9, s10, 25));
	printf("%d\n", strncmp(s9, s10, 25));
}*/
