/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:25:42 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:47:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief converts a lower-case letter to the corresponding upper-case letter
 * @param c character to convert
 * @return the corresponding upper-case letter if c is a lower-case letter,
 * 	c otherwise
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
