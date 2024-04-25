/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:01:58 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:19:50 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief checks for an alphabetic character
 * @param c character to check
 * @return non-zero if the character c is an alphabetic character, zero if not
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
