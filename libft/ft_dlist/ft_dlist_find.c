/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:03:20 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/10 15:11:31 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist_node	*ft_dlist_find(
	t_dlist *lst, void *content, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;

	if (!lst || !lst->head || !content || !cmp)
		return (NULL);
	tmp = lst->head;
	while (tmp)
	{
		if (cmp(tmp->content, content) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
