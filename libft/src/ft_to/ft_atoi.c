/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:08:06 by annabrag          #+#    #+#             */
/*   Updated: 2023/11/23 02:36:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction permet de transformer une chaîne de caractères,
	représentant une valeur entière, en une valeur numérique de type
	int -> ASCII to integer.
	
	Warning!
	La fonction atoi retourne la valeur 0 si la chaîne de caractères
	ne contient pas une représentation de valeur numérique. Il n'est
	donc pas possible de distinguer la chaîne "0" d'une chaîne ne
	contenant pas un nombre entier.

	Valeur de retour:
	- 0 si la chaîne à convertir ne contient pas une donnée numérique
	  entière (int)
	- Une valeur de type int équivalente à la chaîne passée en paramètre.
*/

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

/*int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("Mon atoi: %d\n", ft_atoi(argv[1]));
	printf("Fonction existante: %d\n", atoi(argv[1]));
}*/
