/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:48:03 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 19:05:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Change the static reference stored in `ft_gc_get()` to given node.
 * @param new_head The new head of the garbage collector list.
 */
void	ft_gc_set(t_memblock *new_head)
{
	t_memblock	**head;

	head = ft_gc_get();
	*head = new_head;
}
