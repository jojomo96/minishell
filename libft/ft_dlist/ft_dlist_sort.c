/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:44:02 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 00:45:24 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_sort(t_dlist *lst, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;
	void			*content;
	int				swapped;

	if (!lst || !lst->head || !cmp)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = lst->head;
		while (tmp->next)
		{
			if (cmp(tmp->content, tmp->next->content) > 0)
			{
				content = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = content;
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
}

t_dlist	*ft_dlist_sort_copy(t_dlist *lst, int (*cmp)(void *, void *),
		size_t content_size)
{
	t_dlist			*new_lst;
	t_dlist_node	*tmp;

	if (!lst || !lst->head || !cmp)
		return (NULL);
	new_lst = ft_dlist_new();
	tmp = lst->head;
	while (tmp)
	{
		ft_dlist_append(new_lst, ft_dlist_new_node_deep(tmp->content,
				content_size));
		tmp = tmp->next;
	}
	ft_dlist_sort(new_lst, cmp);
	return (new_lst);
}
