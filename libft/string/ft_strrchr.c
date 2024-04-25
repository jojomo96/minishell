/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:18:11 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief locates the last occurrence of c (converted to an unsigned char)
 * in the string s
 * @param s string to search in
 * @param c character to search for
 * @return a pointer to the located character, or NULL if the character does not
 * appear in the string
 */
char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*res;
	const unsigned char	*us;
	unsigned char		uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	res = NULL;
	if (ft_strlen(s) == 0 && c == 0)
		return ((char *)s);
	if (uc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*us != '\0')
	{
		if (*us == uc)
			res = us;
		us++;
	}
	return ((char *)res);
}
