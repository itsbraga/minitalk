/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:52:34 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:34:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction permet de vider une liste chaînée en
	supprimant tous ses éléments un par un à l'aide de
	la fonction de suppression fournie 'del'.

	Valeur de retour:
	Aucune.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*void	del(void *content)
{
	free(content);
}

int main(void)
{
	t_list	*head = malloc(sizeof(t_list));
	t_list	*second = malloc(sizeof(t_list));
	t_list	*third = malloc(sizeof(t_list));

	head->content = strdup("Premier élément");
	second->content = strdup("Deuxième élément");
	third->content = strdup("Troisième élément");

	// Lier les éléments de la liste
	head->next = second;
	second->next = third;
	third->next = NULL;

	ft_lstclear(&head, del);

	if (head == NULL)
		printf("La liste est vide.\n");
	else
		printf("La liste n'est pas vide.\n");

	return (0);
}*/
