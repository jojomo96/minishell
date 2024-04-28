/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_freeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:04:52 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 16:25:23 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_gc_freeall(void)
{
	t_memblock	**head;
	t_memblock	*current;
	t_memblock	*next;

	head = ft_gc_get();
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->address);
		free(current);
		current = next;
	}
	ft_gc_set(NULL);
}
