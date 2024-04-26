/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:51:30 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief locates the first occurrence of c (converted to a char) in the string
 * pointed to by s. The terminating null character is considered to be part of
 * the string; therefore if c is '\0',
 * the function locates the terminating '\0'.
 * @param s string to search
 * @param c character to search for
 * @return pointer to the located character, or NULL if the character does not
 * appear in the string
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*cs;
	unsigned char	uc;

	cs = (unsigned char *)s;
	uc = (unsigned char)c;
	while (*cs != '\0')
	{
		if (*cs == uc)
			return ((char *)cs);
		cs++;
	}
	if (uc == '\0')
		return ((char *)cs);
	return (NULL);
}
