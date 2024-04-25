/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:43:04 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:40:29 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

/**
 * @brief compares the two strings s1 and s2, but at most n bytes
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n number of bytes to compare
 * @return an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				comp;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 == *us2 && *us1 && n > 1)
	{
		us1++;
		us2++;
		n--;
	}
	if (n > 0)
		comp = *us1 - *us2;
	else
		comp = 0;
	return (comp);
}
