/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:03:07 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 19:02:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief works like `free()` but also removes the address from the gc list
 * @param address The address to free.
 */
void	ft_free(void *address)
{
	t_memblock	**head;
	t_memblock	*prev;
	t_memblock	*next;

	head = ft_gc_get();
	prev = NULL;
	next = *head;
	while (next != NULL)
	{
		if (next->address == address)
		{
			if (prev == NULL)
				*head = next->next;
			else
				prev->next = next->next;
			free(next->address);
			free(next);
			return ;
		}
		prev = next;
		next = next->next;
	}
}
