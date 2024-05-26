/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:55:34 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 12:10:15 by flfische         ###   ########.fr       */
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

void	*ft_gc_add_safe(void *address)
{
	if (address == NULL)
	{
		ft_print_error(strerror(errno), 0, 0);
		ft_destroy_shell(ft_get_shell(), 1);
	}
	ft_gc_add(address);
	return (address);
}
