/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:18:30 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 18:30:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Adds an entry to the environment.
 * @param env The environment to add the entry to.
 * @param key The key of the entry to add.
 * @param val The value of the entry to add.
 * @return 0 on success, -1 on error.
 */
int	ft_env_add(char ***env, char *key, char *val)
{
	int		i;
	char	*entry;
	char	**new_env;
	char	**old_env;

	old_env = *env;
	entry = ft_env_create_entry(key, val);
	if (!entry)
		return (-1);
	i = 0;
	while (old_env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (free(entry), -1);
	i = 0;
	while (old_env[i])
	{
		new_env[i] = old_env[i];
		i++;
	}
	new_env[i] = entry;
	free(*env);
	*env = new_env;
	return (0);
}
