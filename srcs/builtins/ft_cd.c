/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:02:57 by flfische          #+#    #+#             */
/*   Updated: 2024/04/27 13:53:17 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Setting different error codes for different errors.
static int	ft_change_pwd_env(char *new_pwd, char ***env)
{
	char	*old_pwd;
	int		ret;

	old_pwd = ft_env_get(*env, "PWD");
	if (!old_pwd)
		return (-1);
	ret = ft_env_change(env, "OLDPWD", old_pwd);
	free(old_pwd);
	if (ret == -1)
	{
		return (-1);
	}
	ret = ft_env_change(env, "PWD", new_pwd);
	if (ret == -1)
	{
		return (-1);
	}
	return (0);
}

static int	ft_change_dir(char *path, char ***env)
{
	int	ret;

	ret = chdir(path);
	if (ret == -1)
	{
		strerror(errno);
		return (-1);
	}
	ret = ft_change_pwd_env(path, env);
	if (ret == -1)
	{
		return (-1);
	}
	return (0);
}

static int	ft_cd_to_env(char *key, char ***env)
{
	char	*path;
	int		ret;

	path = ft_env_get(*env, key);
	if (!path)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(key, 2);
		ft_putendl_fd(" not set", 2);
		return (1);
	}
	ret = ft_change_dir(path, env);
	free(path);
	if (ret == -1)
		return (1);
	return (0);
}

// TODO: Changing the paramters to use the AST.
int	ft_cd(char ***env, char *path)
{
	int	ret;

	if (!path || !ft_strcmp(path, "--"))
		ret = ft_cd_to_env("HOME", env);
	else if (!ft_strcmp(path, "-"))
		ret = ft_cd_to_env("OLDPWD", env);
	else
		ret = ft_change_dir(path, env);
	if (ret == -1)
		return (1);
	return (ret);
}
