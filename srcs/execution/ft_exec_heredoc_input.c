/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:57:35 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 21:38:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expand_splited_args(char **splited_args)
{
	int	i;

	i = 0;
	while (splited_args[i])
	{
		if (splited_args[i][0] == '$')
			ft_handle_env_variable(&splited_args[i], false, splited_args[i
				+ 1] == NULL);
		i++;
	}
}

static void	ft_read_input_from_terminal(char *delim, int fd,
		bool expand_arguments)
{
	char	*line;
	char	**splited_args;

	while (1)
	{
		if (g_interrupted)
			break ;
		line = readline("> ");
		if (!line || !ft_strcmp(line, delim) || g_interrupted)
		{
			free(line);
			break ;
		}
		ft_gc_safe(line);
		ft_remove_newline(line);
		if (expand_arguments)
		{
			splited_args = ft_split_on_delim(line, &is_delimiter);
			ft_expand_splited_args(splited_args);
			line = ft_strarr_join(splited_args);
		}
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		ft_free(line);
	}
}

static void	ft_read_input_from_pipe(char *delim, int fd, bool expand_arguments)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line && !g_interrupted)
	{
		ft_gc_safe(line);
		ft_remove_newline(line);
		if (!ft_strcmp(line, delim))
		{
			ft_free(line);
			break ;
		}
		if (expand_arguments)
		{
			ft_expand_splited_args(ft_split_on_delim(line, &is_delimiter));
			line = ft_strarr_join(ft_split_on_delim(line, &is_delimiter));
		}
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		ft_free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

static bool	iterprete_delim(char *delim)
{
	bool	expand_arguments;

	expand_arguments = true;
	if (ft_strchr(delim, '"') || ft_strchr(delim, '\''))
	{
		expand_arguments = false;
		ft_remove_all_quotes(delim);
	}
	return (expand_arguments);
}

void	ft_heredoc_read_input(char *delim, char *file_name)
{
	int		fd;
	bool	expand_arguments;

	expand_arguments = iterprete_delim(delim);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (ft_print_error(strerror(errno), 0, 0));
	if (isatty(STDIN_FILENO))
		ft_read_input_from_terminal(delim, fd, expand_arguments);
	else
		ft_read_input_from_pipe(delim, fd, expand_arguments);
	close(fd);
}
