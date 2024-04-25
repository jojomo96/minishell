/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:55:06 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 13:07:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief copies up to dstsize - 1 characters from the string src to dst,
 * NULL-terminating the result if dstsize is not 0.
 * @param dst destination string
 * @param src source string
 * @param dstsize size of the destination buffer
 * @return the total length of the string it tried to create
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len);
}
