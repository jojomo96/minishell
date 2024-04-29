/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:35:41 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 19:04:15 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Holds the static reference to the garbage collector list.
 * @return The first node of garbage collector list.
 */
t_memblock	**ft_gc_get(void)
{
	static t_memblock	*head;

	return (&head);
}
