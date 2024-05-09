/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:52:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 16:06:48 by jmoritz          ###   ########.fr       */
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
		ft_gc_freeall();
		exit(1);
	}
	ft_gc_add(pointer);
	return (pointer);
}
