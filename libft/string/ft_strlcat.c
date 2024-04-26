/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:08:40 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief appends the NUL-terminated string src to the end of dst
 * It will append at most dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate,
	unless dstsize is 0 or the original dst string was longer than dstsize.
 * @param dst destination string
 * @param src source string
 * @param dstsize size of the destination buffer
 * @return the total length of the string it tried to create
 */
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;

	s_len = (unsigned int)ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (s_len);
	d_len = (unsigned int)ft_strlen(dst);
	offset = d_len;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*src && offset < dstsize - 1)
	{
		dst[offset] = *src;
		src++;
		offset++;
	}
	if (offset < dstsize)
		dst[offset] = '\0';
	return ((unsigned int)(d_len + s_len));
}
