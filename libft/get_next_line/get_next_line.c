/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:10:07 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 00:59:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_loop(int fd, char *save, char *line, int *bytes_read);
static char	*ft_get_line(char *save);
static int	ft_reset_save(char *save);

/**
 * @brief	Reads the next line from a file descriptor.
 * @param	fd		The file descriptor to read from.
 * @return	The next line from the file descriptor as a malloced string.
 * NULL if an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	save[OPEN_MAX][GNL_BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	if (GNL_BUFFER_SIZE <= 0 || read(fd, save, 0) == -1)
		return (ft_memcpy(save[fd], "\0", 1), NULL);
	line = ft_strdup(save[fd]);
	if (line == NULL)
		return (NULL);
	line = ft_read_loop(fd, save[fd], line, &bytes_read);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) == 0 && bytes_read == 0)
		return (free(line), NULL);
	temp = ft_get_line(line);
	return (ft_reset_save(save[fd]), free(line), temp);
}

static char	*ft_read_loop(int fd, char *save, char *line, int *bytes_read)
{
	char	*temp;

	*bytes_read = 1;
	while (!ft_strchr(line, '\n') && *bytes_read != 0)
	{
		*bytes_read = read(fd, save, GNL_BUFFER_SIZE);
		if (*bytes_read == -1)
			return (free(line), NULL);
		save[*bytes_read] = '\0';
		temp = ft_strjoin(line, save);
		if (temp == NULL)
			return (free(line), NULL);
		free(line);
		line = temp;
	}
	return (line);
}

static char	*ft_get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_strdup(str);
	return (line);
}

static int	ft_reset_save(char *save)
{
	int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
	{
		ft_memcpy(save, ft_strchr(save, '\n') + 1, ft_strlen(ft_strchr(save,
					'\n')));
		return (1);
	}
	return (0);
}
