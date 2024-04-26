/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:38:49 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 18:29:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Changes the value of an entry in the environment.
 * @param env The environment to change the entry in.
 * @param key The key of the entry to change.
 * @param val The new value of the entry.
 * @return 0 on success, -1 on error.
 */
int	ft_env_change(char ***env, char *key, char *val)
{
	int		i;
	char	**arr;

	arr = *env;
	i = ft_env_index(arr, key);
	if (i == -1)
		return (-1);
	free(arr[i]);
	arr[i] = ft_env_create_entry(key, val);
	if (!arr[i])
		return (-1);
	return (0);
}
