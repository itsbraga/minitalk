/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:29:00 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/24 16:51:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	word_count(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			s += word_len(s, c);
		}
		else
			s++;
	}
	return (counter);
}

static void	*free_f(char **split, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

static char	*ft_strdup2(char const *s, char c)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		counter;

	if (!s)
		return (NULL);
	counter = word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[i] = ft_strdup2(s, c);
			if (!split[i++])
				return (free_f(split, i));
			s += word_len(s, c);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

/*int	main(int argc, char **argv)
{
	int		i;
	char	**split = NULL;

	i = 0;
	if (argc < 3)
		return (0);
	split = ft_split(argv[1], *argv[2]);
	if (!split)
		return (0);
	while (i < word_count(argv[1], argv[2][0]))
	{
		printf("%s\n", split[i++]);
		free(split[i++]);
	}
	free(split);
}*/