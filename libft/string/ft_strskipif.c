/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskipif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:26:11 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 21:34:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Skips characters in a string that match a condition.
 * @param str The string to skip characters in.
 * @param f function that returns 1 if the character should be skipped.
 */
void	ft_strskipif(char **str, int (*f)(int))
{
	while (f(**str))
		(*str)++;
}
