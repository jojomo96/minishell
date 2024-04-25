/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:36:31 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief locates the first occurrence of the null-terminated string needle in
 * the null-terminated string haystack, where not more than len characters are
 * searched. Characters that appear after a '\0' character are not searched.
 * @param haystack string to search in
 * @param needle string to search for
 * @param len maximum number of characters to search
 * @return pointer to the located string, or NULL if the string does not appear
 * in the haystack
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
