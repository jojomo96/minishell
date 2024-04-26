/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:41:47 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:20:42 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief checks for a digit (0 through 9)
 * @param c character to check
 * @return non-zero if the character c is a digit, zero if not
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
