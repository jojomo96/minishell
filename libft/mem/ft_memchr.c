/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:53:12 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 21:14:15 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c
 * @param s memory area to scan
 * @param c character to scan for
 * @param n number of bytes to scan
 * @return a pointer to the matching byte or NULL if the character does not
 * occur in the given memory area
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)&cs[i]);
		i++;
	}
	return (NULL);
}
