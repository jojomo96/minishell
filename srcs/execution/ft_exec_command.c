/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:53:06 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 19:51:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_fds(t_ast_node *node)
{
	if (node->u_data.leaf.fd_in != STDIN_FILENO)
		close(node->u_data.leaf.fd_in);
	if (node->u_data.leaf.fd_out != STDOUT_FILENO)
		close(node->u_data.leaf.fd_out);
	debug_message_1("Closing file descriptors for command:",
		node->u_data.leaf.argv[0]);
	debug_message_1("fd_in:", ft_itoa(node->u_data.leaf.fd_in));
	debug_message_1("fd_out:", ft_itoa(node->u_data.leaf.fd_out));
}

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
		free(path);
		i++;
	}
	ft_strarr_free(paths);
	return (NULL);
}

// gets the path of the command
char	*ft_get_path(t_shell *ms, char *arg)
{
	char	*path_env;

	if (ft_isdir(arg) && ft_strcmp(arg, ".") != 0 && ft_strcmp(arg, "..") != 0)
	{
		errno = EISDIR;
		return (NULL);
	}
	if (ft_strncmp(arg, "./", 2) == 0 || ft_strncmp(arg, "/", 1) == 0
		|| ft_strncmp(arg, "../", 3) == 0 || access(arg, F_OK) == 0)
		return (ft_strdup(arg));
	path_env = ft_env_get(ms->env, "PATH");
	if (!path_env)
		return (NULL);
	return (ft_get_path_from_env(path_env, arg));
}

static void	handle_execve_err(char *path, char *arg, t_shell *ms)
{
	if (ft_strcmp(arg, ".") == 0)
	{
		ft_print_error("filename argument required", arg, NULL);
		ft_putendl_fd(".: usage: . filename [arguments]", STDERR_FILENO);
		ft_destroy_shell(ms, 0);
		exit(2);
	}
	if (path && ft_strcmp(path, arg) == 0 && !(ft_strncmp(arg, "./", 2) == 0
			|| ft_strncmp(arg, "/", 1) == 0 || ft_strncmp(arg, "../", 3) == 0))
		ft_print_error("command not found", arg, NULL);
	else
		ft_print_error(strerror(errno), arg, NULL);
	ft_destroy_shell(ms, 0);
	strerror(errno);
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	exit(127);
}

// executes external commands
int	ft_exec_command(t_shell *ms, t_ast_node *node)
{
	char	*path;
	pid_t	pid;
	int		std_out;
	int		std_in;

	debug_message_1("Executing command:", node->u_data.leaf.argv[0]);
	std_out = dup(STDOUT_FILENO);
	std_in = dup(STDIN_FILENO);
	pid = fork();
	node->u_data.leaf.pid = pid;
	if (pid == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (pid == 0)
	{
		if (node->u_data.leaf.fd_in != STDIN_FILENO)
		{
			dup2(node->u_data.leaf.fd_in, STDIN_FILENO);
			close(std_in);
		}
		if (node->u_data.leaf.fd_out != STDOUT_FILENO)
		{
			dup2(node->u_data.leaf.fd_out, STDOUT_FILENO);
			close(std_out);
		}
		fr_traverse_and_process(ms->ast, AST_TYPE_LEAF, &ft_close_fds);
		path = ft_get_path(ms, node->u_data.leaf.argv[0]);
		if (!path)
			return (handle_execve_err(path, node->u_data.leaf.argv[0], ms), 1);
		if (execve(path, node->u_data.leaf.argv, ms->env) == -1)
			return (handle_execve_err(path, node->u_data.leaf.argv[0], ms), 1);
		return (debug_message(path), free(path), exit(1), 1);
	}
	return (0);
}
