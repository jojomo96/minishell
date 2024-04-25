/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:10:52 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief writes len bytes of value c (converted to an unsigned char)
 * to the string b.
 * @param b string to write to
 * @param c value to write
 * @param len number of bytes to write
 * @return b
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (char *)b;
	while (i < len)
		cpy[i++] = c;
	return (b);
}
