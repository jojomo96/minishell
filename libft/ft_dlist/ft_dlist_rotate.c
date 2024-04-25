/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:46:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:44:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_rotate(t_dlist *lst)
{
	t_dlist_node	*first;

	if (!lst || !lst->head || !lst->tail || lst->head == lst->tail)
		return ;
	first = lst->head;
	lst->head = first->next;
	lst->head->prev = NULL;
	lst->tail->next = first;
	first->prev = lst->tail;
	first->next = NULL;
	lst->tail = first;
}

void	ft_dlist_reverse_rotate(t_dlist *lst)
{
	t_dlist_node	*last;

	if (!lst || !lst->head || !lst->tail || lst->head == lst->tail)
		return ;
	last = lst->tail;
	lst->tail = last->prev;
	lst->tail->next = NULL;
	last->prev = NULL;
	last->next = lst->head;
	lst->head->prev = last;
	lst->head = last;
}
