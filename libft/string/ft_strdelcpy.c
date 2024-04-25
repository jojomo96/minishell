/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:13:05 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 13:15:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief copies up to the first occurrence of the delimiter character from the
 * source string to the destination string, NULL-terminating the result. If the
 * delimiter character is not found, the entire source string is copied.
 * @param dest destination string
 * @param src source string
 * @param del delimiter character
 * @return the destination string
 */
char	*ft_strdelcpy(char *dest, const char *src, char del)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != del)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
