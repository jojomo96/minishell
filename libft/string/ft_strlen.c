/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:20:28 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief calculates the length of the string s, excluding the terminating null
 * byte ('\0')
 * @param s string to calculate the length of
 * @return the number of characters in the string s
 */
size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
