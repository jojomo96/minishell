/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:59:13 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 17:01:43 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Compares two strings.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return The difference between the first differing characters.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
