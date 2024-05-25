/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:57:35 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 15:02:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_read_input_from_terminal(char *delim, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delim))
		{
			free(line);
			break ;
		}
		ft_remove_newline(line);
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

static void	ft_read_input_from_pipe(char *delim, int fd)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_remove_newline(line);
		if (!ft_strcmp(line, delim))
		{
			free(line);
			break ;
		}
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

void	ft_heredoc_read_input(char *delim, char *file_name)
{
	int		fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (ft_print_error(strerror(errno), 0, 0));
	if (isatty(STDIN_FILENO))
		ft_read_input_from_terminal(delim, fd);
	else
		ft_read_input_from_pipe(delim, fd);
	close(fd);
}
