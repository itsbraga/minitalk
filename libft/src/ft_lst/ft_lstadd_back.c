/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:22:00 by annabrag          #+#    #+#             */
/*   Updated: 2023/12/07 19:33:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*	Description:
	Cette fonction ajoute un nouvel élément à la fin d'une
	liste chaînée, en mettant à jour les pointeurs appropriés
	pour maintenir la cohérence de la liste.
	La liste est représentée par un pointeur vers le pointeur
	de tête (lst) et le nouvel élément est représenté par un
	pointeur (new).

	Valeur de retour:
	Aucune.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	else
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
	t_list 	*elem3 = ft_lstnew("Troisième élément");

	ft_lstadd_back(&head, elem1);
	ft_lstadd_back(&head, elem2);
	ft_lstadd_back(&head, elem3);

	print_list(head);

	return (0);
}*/
