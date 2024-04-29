/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printgc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:07:08 by flfische          #+#    #+#             */
/*   Updated: 2024/04/28 17:17:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_printgc(void)
{
	t_memblock	**head;
	t_memblock	*current;

	if (DEBUG == 0)
		return ;
	head = ft_gc_get();
	if (*head == NULL)
	{
		printf("No addresses in the garbage collector\n");
		return ;
	}
	printf("Addresses in the garbage collector:\n");
	current = *head;
	while (current != NULL)
	{
		printf("\t%p\n", current->address);
		current = current->next;
	}
}
