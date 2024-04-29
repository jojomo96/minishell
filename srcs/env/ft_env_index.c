/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:20:29 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 18:29:47 by flfische         ###   ########.fr       */
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

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, ft_strlen(key)) == 0)
		{
			if (env[i][ft_strlen(key)] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}
