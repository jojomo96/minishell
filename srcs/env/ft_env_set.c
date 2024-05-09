/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:30:36 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 18:02:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Set the value of an environment variable.
 * If the variable does not exist, it will be created.
 * @param env The environment to set the variable in.
 * @param key The key of the variable to set.
 * @param val The value to set the variable to.
 * @return int 0 on success, -1 on error.
 */
int	ft_env_set(char ***env, char *key, char *val)
{
	if (ft_valid_env_key(key) == -1)
	{
		ft_print_error_env("not a valid identifier", "export", key);
		return (-1);
	}
	if (ft_env_index(*env, key) == -1)
		return (ft_env_add(env, key, val));
	return (ft_env_change(env, key, val));
}
