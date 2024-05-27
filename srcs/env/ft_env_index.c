/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:20:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 20:04:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Gets the index of an entry in the environment.
 * @param env The environment to search in.
 * @param key The key of the entry to search for.
 * @return The index of the entry on success, -1 on error or not found.
 */
int	ft_env_index(char **env, char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0)
		{
			if (env[i][len] == '=' || env[i][len] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}
