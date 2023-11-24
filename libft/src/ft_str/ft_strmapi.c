/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:07:33 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_copy;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_copy)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		s_copy[i] = f(i, s[i]);
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

/*char    f(unsigned int i, char c)
{
	char        res;

    res = (char)(i + (unsigned int)c) + 1;
	return (res);
}

int main(void)
{
    char    s[] = "abc";
    char    *s_copy;
	s_copy = ft_strmapi(s, *f);
	printf("%s\n", s_copy);
}*/
