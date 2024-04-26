/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:55 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:21:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief checks for any printable character
 * @param c character to check
 * @return non-zero if the character c is a printable character (32 to 126),
	zero if not
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
