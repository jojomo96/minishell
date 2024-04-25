/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:52:33 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content of
 * each element.
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || (*f) == NULL)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
