/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:48:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/04 09:22:41 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		return (ft_malloc(new_size));
	}
	else
	{
		new_ptr = ft_malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		ft_memcpy(new_ptr, ptr, copy_size);
		ft_free(ptr);
		return (new_ptr);
	}
}
