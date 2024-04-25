/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:41:55 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Deletes and frees the given element using the function ’del’ and
 * free(3).
 * @param lst The element to free and delete.
 * @param del The address of the function used to delete the content of the
 * element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || (*del) == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
