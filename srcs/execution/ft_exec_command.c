/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:53:06 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 16:00:30 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// gets the path of the command from the PATH environment variable
char	*ft_get_path_from_env(char *path_env, char *arg)
{
	char	**paths;
	char	*tmp;
	char	*path;
	int		i;

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin(tmp, arg);
		free(tmp);
		if (!path)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_strarr_free(paths), path);
	}
	ft_strarr_free(paths);
	return (NULL);
}

// gets the path of the command
char	*ft_get_path(t_shell *ms, char *arg)
{
	char	*path_env;

	if (ft_isfdir(arg) && ft_strcmp(arg, ".") != 0 && ft_strcmp(arg, "..") != 0)
	{
		errno = EISDIR;
		return (NULL);
	}
	if (ft_strncmp(arg, "./", 2) == 0 || ft_strncmp(arg, "/", 3) == 0
		|| ft_strncmp(arg, "../", 3) == 0 || access(arg, F_OK) == 0)
		return (ft_strdup(arg));
	path_env = ft_env_get(ms->env, "PATH");
	if (!path_env)
		return (NULL);
	return (ft_get_path_from_env(path_env, arg));
}

// executes external commands
int	ft_exec_command(t_shell *ms, t_ast_node *node)
{
	char	*path;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (pid == 0)
	{
		path = ft_get_path(ms, node->u_data.leaf.argv[0]);
		if (!path)
			return (ft_print_error(strerror(errno), NULL, NULL), 1);
		if (execve(path, node->u_data.leaf.argv, ms->env) == -1)
			return (ft_print_error(strerror(errno), NULL, NULL), 1);
		free(path);
	}
}
