/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:54:41 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Copies len bytes from string src to string dst.  The two strings
 * may overlap; the copy is always done in a non-destructive manner.
 *	@param dst The address of the destination string.
 *	@param src The address of the source string.
 *	@param n The number of bytes to copy.
 *	@return A pointer to the destination string dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	if (dst == NULL && src == NULL && n)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (cdst < csrc)
	{
		i = 0;
		while (i++ < n)
			*cdst++ = *csrc++;
	}
	else
	{
		i = n;
		while (i > 0)
		{
			cdst[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dst);
}
