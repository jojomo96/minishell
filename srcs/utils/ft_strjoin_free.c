/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:59:43 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 14:37:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Joins two strings `s1` and `s2` together and returns the result.
 * If `to_free` is non-zero, it frees the memory allocated for `s1` and `s2`
 * after joining.
 *
 * @param s1 The first string to be joined.
 * @param s2 The second string to be joined.
 * @param to_free Flag indicating whether to free the memory for `s1` and `s2`
 *                after joining.
 *                Set to 1 to free the memory, 0 otherwise.
 * @return The joined string.
 */
char	*ft_strjoin_free(char *s1, char *s2, int to_free)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strjoin(s1, s2);
	ft_gc_safe(str);
	if (to_free == 1 || to_free == 3)
		ft_free(s1);
	if (to_free == 2 || to_free == 3)
		ft_free(s2);
	return (str);
}

t_in_quotes	ft_init_quotes(void)
{
	t_in_quotes	q;

	q.in_s_quotes = false;
	q.in_d_quotes = false;
	return (q);
}
