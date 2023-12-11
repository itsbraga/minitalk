/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:56:57 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:46:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction permet de tester si un caractère
	est alpha-numérique ou non.
	
	Warning!
	On ne traite que les caractères purs ASCII (-> 127).

	Valeur de retour:
	-	Une valeur positive non nulle si c'est un
		caractère alpha-numérique.
	-	0 si c'est un caractère alpha-numérique.
*/

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
