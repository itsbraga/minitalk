/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:27:04 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:44:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction alloue un bloc de mémoire en initialisant
	tous ses octets à la valeur 0. Bien que relativement
	proche de la fonction malloc, deux aspects les
	différencient :
	
	⋆ L'initialisation :	calloc met tous les octets du
				bloc à la valeur 0, alors que
				malloc ne modifie pas la zone
				de mémoire.
	⋆ Les paramètres d'appels :	calloc requière deux paramètres
					(le nombre d'éléments consécutifs
					à allouer (nmemb) et la taille
					d'un élément (size)) alors que
					malloc attend la taille totale
					du bloc à allouer.
	
	Valeur de retour:
	Un pointeur sur la zone nouvellement allouée.
	Attention, il s'agit d'un pointeur générique (void *),
	il peut donc être nécessaire de caster le pointeur
	vers un autre type.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size != 0 && nmemb > (sizeof(char) * 2147483424) / size)
		return (NULL);
	ret = (void *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, (nmemb * size));
	return (ret);
}
