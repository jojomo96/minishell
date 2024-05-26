/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:52:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 17:31:51 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Discuss if malloc fail should result in exit or just print error.
/**
 * @brief works like `malloc()` but also adds the address to the gc list
 * @param size The size of the memory to allocate.
 * @return The pointer to the allocated memory. NULL if allocation failed.
 */
void	*ft_malloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		ft_print_error(strerror(errno), 0, 0);
		ft_destroy_shell(ft_get_shell(), 1);
		exit(1);
	}
	ft_gc_add(pointer);
	return (pointer);
}
