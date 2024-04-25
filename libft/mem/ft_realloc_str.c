/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:04:37 by flfische          #+#    #+#             */
/*   Updated: 2024/04/24 21:09:09 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Reallocates a string to a new length.
 *	@param str The address of the string to reallocate.
 *	@param len The current length of the string.
 *	@param new_len The new length of the string.
 * @return int 0 if the reallocation was successful, -1 if malloc failed,
	or 1 if the new length is less than or equal to the current length
 */
int	ft_realloc_str(char **str, size_t len, size_t new_len)
{
	char	*new;

	if (new_len <= len || !*str)
		return (1);
	new = malloc(new_len);
	if (!new)
	{
		free(*str);
		return (-1);
	}
	ft_memcpy(new, *str, len);
	free(*str);
	*str = new;
	return (0);
}
