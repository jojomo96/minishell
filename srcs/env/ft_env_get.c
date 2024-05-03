/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:20:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/03 10:52:34 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Setting different error codes for different errors.
/**
 * @brief Get the value of an environment variable.
 * @param env The environment variables.
 * @param key The key of the environment variable.
 * @return The value of the environment variable or
 * NULL if the environment variable does not exist.
 */
char	*ft_env_get(char **env, char *key)
{
	int		i;
	char	*entry;
	char	*val;
	char	**temp;

	i = ft_env_index(env, key);
	if (i == -1)
		return (NULL);
	entry = env[i];
	temp = ft_split(entry, '=');
	if (temp == NULL)
		return (NULL);
	if (temp[1] == NULL)
		val = ft_strdup("");
	else
		val = ft_strdup(temp[1]);
	if (val == NULL)
		return (NULL);
	if (temp[1] != NULL)
		free(temp[2]);
	free(temp[0]);
	free(temp[1]);
	free(temp);
	return (val);
}
