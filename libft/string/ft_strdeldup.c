/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeldup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:15:54 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 13:20:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a copy of the string 'src'
 * up to the first occurrence of the delimiter character 'del'.
 * The copy is NULL-terminated.
 * If the delimiter character is not found, the entire source string is copied.
 * @param src The string to copy.
 * @param del The delimiter character.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strdeldup(const char *src, char del)
{
	char	*dest;

	dest = (char *)malloc(ft_strdellen(src, del) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strdelcpy(dest, src, del);
	return (dest);
}
