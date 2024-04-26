/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:18 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/**
 * @brief allocates (with malloc(3)) and returns a copy of s1
 * with the characters specified in set
 * removed from the beginning and the end of the string
 * @param s1 string to trim
 * @param set set of characters to trim
 * @return the trimmed string, or NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	len = ft_strlen(s1 + start);
	while (len > 0 && in_set(s1[start + len - 1], set))
		len--;
	trim = malloc(len + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}
