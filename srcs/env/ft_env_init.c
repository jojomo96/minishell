/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:33:04 by flfische          #+#    #+#             */
/*   Updated: 2024/05/24 18:49:47 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_shlvl_nbr(char *str)
{
	int	shlvl;
	int	i;

	i = 0;
	shlvl = 0;
	if (str[i] == '\0')
		shlvl = 1000;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && !(i == 0 && str[i] == '-'))
			return (1);
		shlvl = shlvl * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		return (0);
	if (shlvl > 999)
	{
		ft_putstr_fd("minishell: warning: shell level (", STDERR_FILENO);
		ft_putnbr_fd(shlvl + 1, STDERR_FILENO);
		ft_putstr_fd(") too high, resetting to 1\n", STDERR_FILENO);
		shlvl = 0;
	}
	shlvl++;
	return (shlvl);
}

static int	ft_handle_shlvl(char ***env)
{
	char	*env_shlvl;
	char	*new_shlvl;
	int		shlvl;
	int		status;

	env_shlvl = ft_env_get(*env, "SHLVL");
	if (env_shlvl == NULL)
		return (ft_env_add(env, "SHLVL", "1"));
	shlvl = ft_get_shlvl_nbr(env_shlvl);
	if (shlvl == 1000)
		new_shlvl = ft_strdup("");
	else
		new_shlvl = ft_itoa(shlvl);
	if (new_shlvl == NULL)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	status = ft_env_change(env, "SHLVL", new_shlvl);
	ft_free(env_shlvl);
	ft_free(new_shlvl);
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
	ft_env_remove(env, "OLDPWD");
	return (status);
}
