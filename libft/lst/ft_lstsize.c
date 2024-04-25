/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:59:21 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*next;

	if (lst == NULL)
		return (0);
	size = 0;
	next = lst;
	while (next != NULL)
	{
		next = next->next;
		size++;
	}
	return (size);
}
