/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:02:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 18:27:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Setting different error codes for different errors.
static int	ft_change_pwd_env(char *new_pwd, t_shell *ms)
{
	char	*old_pwd;
	int		ret;

	old_pwd = ft_env_get(ms->env, "PWD");
	if (!old_pwd)
		return (-1);
	ret = ft_env_set_both(ms, "OLDPWD", old_pwd);
	ft_free(old_pwd);
	if (ret == -1)
		return (-1);
	ret = ft_env_set_both(ms, "PWD", new_pwd);
	if (ret == -1)
		return (-1);
	return (0);
}

static int	ft_change_dir(char *path, t_shell *ms)
{
	int	ret;

	ret = chdir(path);
	if (ret == -1)
	{
		ft_print_error(strerror(errno), "cd", path);
		return (-1);
	}
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_print_error(strerror(errno), "cd", NULL);
		return (-1);
	}
	ret = ft_change_pwd_env(path, ms);
	if (ret == -1)
		return (-1);
	free(path);
	return (0);
}

static int	ft_cd_to_env(char *key, t_shell *ms)
{
	char	*path;
	int		ret;

	path = ft_env_get(ms->env, key);
	if (!path)
	{
		if (!ft_strcmp(key, "HOME"))
			ft_print_error("HOME not set", "cd", NULL);
		else if (!ft_strcmp(key, "OLDPWD"))
			ft_print_error("OLDPWD not set", "cd", NULL);
		else if (!ft_strcmp(key, "PWD"))
			ft_print_error("PWD not set", "cd", NULL);
		return (1);
	}
	ret = ft_change_dir(path, ms);
	ft_free(path);
	if (ret == -1)
		return (1);
	return (0);
}

/**
 * @brief Change the current working directory.
 * @note old bash does not print error if argc > 2
 */
int	ft_cd(t_shell *ms, char **argv, int fd_out)
{
	int		ret;
	char	*path;

	debug_message("executing builtin: cd");
	path = argv[1];
	if (argv[1] && argv[2])
	{
		ft_print_error("too many arguments", "cd", NULL);
		return (1);
	}
	if (!path || !ft_strcmp(path, "--"))
		ret = ft_cd_to_env("HOME", ms);
	else if (!ft_strcmp(path, "-"))
	{
		ret = ft_cd_to_env("OLDPWD", ms);
		if (ret == 0)
			ft_pwd(fd_out);
	}
	else
		ret = ft_change_dir(path, ms);
	if (ret == -1)
		return (1);
	return (ret);
}
