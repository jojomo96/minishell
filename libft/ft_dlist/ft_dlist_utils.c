/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:48:51 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:43:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist_node	*ft_dlist_peek_front(t_dlist *lst)
{
	if (!lst || !lst->head)
		return (NULL);
	return (lst->head);
}

t_dlist_node	*ft_dlist_peek_back(t_dlist *lst)
{
	if (!lst || !lst->tail)
		return (NULL);
	return (lst->tail);
}

size_t	ft_dlist_size(t_dlist *lst)
{
	if (!lst)
		return (0);
	return (lst->size);
}

void	ft_dlist_node_destroy(t_dlist_node **node, void (*del)(void *))
{
	if (!node || !*node)
		return ;
	if (del)
		del((*node)->content);
	free(*node);
	*node = NULL;
}

void	ft_dlist_print(t_dlist *lst, void (*print)(t_dlist_node *))
{
	t_dlist_node	*tmp;

	if (!lst || !print)
		return ;
	tmp = lst->head;
	while (tmp)
	{
		print(tmp);
		tmp = tmp->next;
	}
}
