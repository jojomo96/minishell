/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:15:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 08:27:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_split_state
{
	int					str_idx;
	int					buffer_idx;
	int					result_idx;
	char				**result;
	char				*buffer;
	bool				found_question_mark;
}						t_split_state;

static t_split_state	*ft_init_split_state(const char *str)
{
	t_split_state	*state;

	state = malloc(sizeof(t_split_state));
	if (!state)
		return (NULL);
	state->result = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!state->result)
	{
		free(state);
		return (NULL);
	}
	state->buffer = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!state->buffer)
	{
		free(state->result);
		free(state);
		return (NULL);
	}
	state->str_idx = 0;
	state->result_idx = 0;
	state->buffer_idx = 0;
	state->found_question_mark = false;
	return (state);
}

static void	ft_handle_split(t_split_state *state, char *str)
{
	state->found_question_mark = false;
	state->buffer[state->buffer_idx] = '\0';
	if (state->buffer_idx != 0)
		state->result[state->result_idx++] = ft_strdup(state->buffer);
	state->buffer_idx = 0;
	while (str[state->str_idx] == '\'' || str[state->str_idx] == '\"'
		|| str[state->str_idx] == ' ')
	{
		state->buffer[state->buffer_idx] = str[state->str_idx];
		state->buffer[++state->buffer_idx] = '\0';
		state->result[state->result_idx++] = ft_strdup(state->buffer);
		state->buffer_idx = 0;
		state->str_idx++;
	}
	if (str[state->str_idx] != '\0')
	{
		state->buffer[state->buffer_idx] = str[state->str_idx];
		state->buffer_idx++;
	}
	state->str_idx++;
}

char	**ft_split_on_delim(const char *str, bool(delim)(char c))
{
	t_split_state	*state;

	state = ft_init_split_state(str);
	state->found_question_mark = false;
	while (str[state->str_idx] != '\0')
	{
		if (!delim(str[state->str_idx]) && !state->found_question_mark)
		{
			if (str[state->str_idx] == '?')
				state->found_question_mark = true;
			state->buffer[state->buffer_idx++] = str[state->str_idx++];
		}
		else
			ft_handle_split(state, (char *)str);
	}
	if (state->buffer_idx != 0)
	{
		state->buffer[state->buffer_idx] = '\0';
		state->result[state->result_idx++] = ft_strdup(state->buffer);
	}
	free(state->buffer);
	state->result[state->result_idx] = NULL;
	return (state->result);
}
