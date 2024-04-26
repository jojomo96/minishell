/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:00:50 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:20:23 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief checks for an ASCII character
 * @param c character to check
 * @return non-zero if the character c is an ASCII character (0 to 127),
	zero if not
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
