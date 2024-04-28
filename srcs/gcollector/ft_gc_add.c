/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:55:34 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 19:03:00 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Adds an address to the garbage collector list.
 * @param address The address to add.
 */
void	ft_gc_add(void *address)
{
	t_memblock	**head;
	t_memblock	*new_block;

	head = ft_gc_get();
	new_block = malloc(sizeof(t_memblock));
	if (new_block == NULL)
	{
		ft_print_error(strerror(errno), 0, 0);
		return ;
	}
	new_block->address = address;
	new_block->next = *head;
	*head = new_block;
}
