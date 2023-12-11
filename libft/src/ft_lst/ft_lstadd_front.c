/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:39:24 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:34:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction ajoute un nouvel élément au début
	d'une liste chaînée en mettant à jour les pointeurs
	appropriés pour maintenir la cohérence de la liste.

	Valeur de retour:
	Aucune.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

/*void	print_list(t_list *head)
{
	t_list	*curr = head;

	while (curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
}

int	main(void)
{
	t_list	*head = NULL;
	t_list	*elem1 = ft_lstnew("Premier élément");
	t_list	*elem2 = ft_lstnew("Deuxième élément");
	t_list	*elem3 = ft_lstnew("Troisième élément");

	ft_lstadd_front(&head, element3);
	ft_lstadd_front(&head, element2);
	ft_lstadd_front(&head, element1);

	print_list(head);

	return (0);
}*/