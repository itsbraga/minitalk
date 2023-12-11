/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:56:05 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:35:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction applique la fonction 'f' à chaque
	élément de la liste chaînée 'lst' permettant ainsi
	de traiter tous les éléments de la liste d'une
	manière spécifique définie par la fonction f.

	Valeur de retour:
	Aucune.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*elem1 = ft_lstnew("Élément 1");
	t_list	*elem2 = ft_lstnew("Élément 2");
	t_list	*elem3 = ft_lstnew("Élément 3");

	// Lier les éléments pour former une liste
	elem1->next = elem2;
	elem2->next = elem3;

	ft_lstiter(elem1, print_content);

	return (0);
}*/
