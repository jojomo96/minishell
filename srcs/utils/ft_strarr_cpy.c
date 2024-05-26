/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:12:52 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 19:27:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Creates a deep copy of a string array.
 * @param arr The string array to copy.
 * @return The copied string array on success, NULL on error.
 */
char	**ft_strarr_cpy(char **arr)
{
	int		i;
	char	**cpy;

	i = 0;
	while (arr[i])
		i++;
	cpy = ft_malloc((i + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		cpy[i] = ft_gc_safe(ft_strdup(arr[i]));
		if (!cpy[i])
		{
			ft_strarr_free(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
