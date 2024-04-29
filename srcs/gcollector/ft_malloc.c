/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:52:29 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 19:06:56 by flfische         ###   ########.fr       */
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
		return (NULL);
	}
	ft_gc_add(pointer);
	return (pointer);
}
