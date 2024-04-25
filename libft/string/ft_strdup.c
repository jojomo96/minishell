/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:07:15 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief allocates sufficient memory for a copy of the string s1,
 * does the copy, and returns a pointer to it.
 * if allocation fails, returns NULL and sets errno to ENOMEM
 * @param s1 string to copy
 * @return pointer to the copy of s1
 */
char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dest = (char *)malloc(len);
	if (dest == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(dest, s1, len);
	return (dest);
}
