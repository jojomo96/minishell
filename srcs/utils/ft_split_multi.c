/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:15:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 08:24:13 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_split_multi
{
	int					i;
	int					j;
	int					k;
	char				**result;
	char				*temp;
	bool				was_question_mark;
}						t_split_multi;

static t_split_multi	*init_split_multi(const char *str)
{
	t_split_multi	*split_multi;

	split_multi = malloc(sizeof(t_split_multi));
	if (!split_multi)
		return (NULL);
	split_multi->result = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!split_multi->result)
	{
		free(split_multi);
		return (NULL);
	}
	split_multi->temp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!split_multi->temp)
	{
		free(split_multi->result);
		free(split_multi);
		return (NULL);
	}
	split_multi->i = 0;
	split_multi->j = 0;
	split_multi->k = 0;
	split_multi->was_question_mark = false;
	return (split_multi);
}

static void	ft_handle_split(t_split_multi *s, char *str)
{
	s->was_question_mark = false;
	s->temp[s->j] = '\0';
	if (s->j != 0)
		s->result[s->k++] = ft_strdup(s->temp);
	s->j = 0;
	while (str[s->i] == '\'' || str[s->i] == '\"' || str[s->i] == ' ')
	{
		s->temp[s->j] = str[s->i];
		s->temp[++s->j] = '\0';
		s->result[s->k++] = ft_strdup(s->temp);
		s->j = 0;
		s->i++;
	}
	if (str[s->i] != '\0')
	{
		s->temp[s->j] = str[s->i];
		s->j++;
	}
	s->i++;
}

// Function to split the string while keeping the delimiter
char	**ft_split_on_delim(const char *str, bool(delim)(char c))
{
	t_split_multi	*s;

	s = init_split_multi(str);
	s->was_question_mark = false;
	while (str[s->i] != '\0')
	{
		if (!delim(str[s->i]) && !s->was_question_mark)
		{
			if (str[s->i] == '?')
				s->was_question_mark = true;
			s->temp[s->j++] = str[s->i++];
		}
		else
			ft_handle_split(s, (char *)str);
	}
	if (s->j != 0)
	{
		s->temp[s->j] = '\0';
		s->result[s->k++] = ft_strdup(s->temp);
	}
	free(s->temp);
	s->result[s->k] = NULL;
	return (s->result);
}
