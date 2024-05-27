/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:07:06 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 19:29:13 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: maybe we should reallocate to smaller size if we remove an entry
// not sure if it's worth the effort
/**
 * @brief Removes an entry from the environment.
 * @param env The environment to remove the entry from.
 * @param key The key of the entry to remove.
 * @return 0 on success, -1 on error.
 */
int	ft_env_remove(char ***env, char *key)
{
	int		i;
	char	**arr;

	arr = *env;
	i = ft_env_index(arr, key);
	if (i == -1)
		return (0);
	ft_free(arr[i]);
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (0);
}
