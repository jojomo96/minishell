/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:33:04 by flfische          #+#    #+#             */
/*   Updated: 2024/05/01 14:04:36 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_shlvl(char ***env)
{
	char	*env_shlvl;
	char	*new_shlvl;
	int		shlvl;
	int		status;

	env_shlvl = ft_env_get(*env, "SHLVL");
	if (env_shlvl == NULL)
		return (ft_env_add(env, "SHLVL", "1"));
	shlvl = ft_atoi(env_shlvl) + 1;
	new_shlvl = ft_itoa(shlvl);
	if (new_shlvl == NULL)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	status = ft_env_change(env, "SHLVL", new_shlvl);
	free(new_shlvl);
	return (status);
}

static int	ft_env_init_pwd(char ***env)
{
	char	*pwd;
	int		status;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_print_error(strerror(errno), "pwd", NULL), 1);
	status = ft_env_add(env, "PWD", pwd);
	free(pwd);
	return (status);
}

/**
 * Initializes the environment by setting the PWD if it is not set and
 * incrementing the SHLVL variable.
 * @param env The environment to initialize.
 * @return 0 on success, 1 on error.
 */
int	ft_env_init(char ***env)
{
	int	status;

	status = ft_handle_shlvl(env);
	if (status != 0)
		return (status);
	if (ft_env_index(*env, "PWD") == -1)
		status = ft_env_init_pwd(env);
	return (status);
}
