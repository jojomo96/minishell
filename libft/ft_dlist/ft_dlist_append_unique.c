/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_append_unique.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:59:59 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/11 17:34:32 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdio.h>

bool	ft_dlist_append_unique(t_dlist *lst, t_dlist_node *new,
		int (*cmp)(void *, void *))
{
	t_dlist_node	*current;

	if (!lst || !new)
		return (false);
	current = lst->head;
	while (current)
	{
		if (cmp(current->content, new->content) == 0)
			return (false);
		current = current->next;
	}
	ft_dlist_append(lst, new);
	return (true);
}
