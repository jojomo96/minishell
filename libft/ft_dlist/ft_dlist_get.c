/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:55:35 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 00:44:08 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	*ft_dlist_get(t_dlist *lst, int index)
{
	t_dlist_node	*tmp;
	int				i;

	if (!lst || !lst->head || index < 0)
		return (NULL);
	i = 0;
	tmp = lst->head;
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == index)
		return (tmp->content);
	return (NULL);
}

int	ft_dlist_index_of(t_dlist *lst, void *content, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;
	int				i;

	if (!lst || !lst->head || !cmp)
		return (-1);
	i = 0;
	tmp = lst->head;
	while (tmp)
	{
		if (cmp(tmp->content, content) == 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	*ft_dlist_get_max(t_dlist *lst, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;
	void			*max;

	if (!lst || !lst->head || !cmp)
		return (NULL);
	tmp = lst->head;
	max = tmp->content;
	while (tmp)
	{
		if (cmp(tmp->content, max) > 0)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

void	*ft_dlist_get_min(t_dlist *lst, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;
	void			*min;

	if (!lst || !lst->head || !cmp)
		return (NULL);
	tmp = lst->head;
	min = tmp->content;
	while (tmp)
	{
		if (cmp(tmp->content, min) < 0)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_dlist_is_sorted(t_dlist *lst, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;

	if (!lst || !lst->head || !cmp)
		return (0);
	tmp = lst->head;
	while (tmp->next)
	{
		if (cmp(tmp->content, tmp->next->content) > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
