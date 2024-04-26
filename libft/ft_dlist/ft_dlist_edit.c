/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_edit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:18:19 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:43:31 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_prepend(t_dlist *lst, t_dlist_node *new)
{
	if (!lst || !new)
		return ;
	if (lst->head)
	{
		new->next = lst->head;
		lst->head->prev = new;
	}
	lst->head = new;
	if (!lst->tail)
		lst->tail = new;
	lst->size++;
}

void	ft_dlist_append(t_dlist *lst, t_dlist_node *new)
{
	if (!lst || !new)
		return ;
	if (!lst->head)
	{
		lst->head = new;
		lst->tail = new;
		lst->size++;
		return ;
	}
	lst->tail->next = new;
	new->prev = lst->tail;
	lst->tail = new;
	lst->size++;
}

t_dlist_node	*ft_dlist_pop_front(t_dlist *lst)
{
	t_dlist_node	*first;

	if (!lst || !lst->head)
		return (NULL);
	first = lst->head;
	lst->head = first->next;
	if (lst->head)
		lst->head->prev = NULL;
	else
		lst->tail = NULL;
	first->next = NULL;
	first->prev = NULL;
	lst->size--;
	return (first);
}

t_dlist_node	*ft_dlist_pop_back(t_dlist *lst)
{
	t_dlist_node	*last;

	if (!lst || !lst->head)
		return (NULL);
	last = lst->tail;
	if (last->prev)
		last->prev->next = NULL;
	else
		lst->head = NULL;
	lst->tail = last->prev;
	last->next = NULL;
	last->prev = NULL;
	lst->size--;
	return (last);
}
