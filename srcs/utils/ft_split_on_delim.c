/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_on_delim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:15:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/23 16:52:18 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_split_state	*ft_init_split_state(const char *str)
{
	t_split_state	*state;

	state = ft_malloc(sizeof(t_split_state));
	if (!state)
		return (NULL);
	state->result = ft_malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!state->result)
	{
		ft_free(state);
		return (NULL);
	}
	state->buffer = ft_malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!state->buffer)
	{
		ft_free(state->result);
		ft_free(state);
		return (NULL);
	}
	state->str_idx = 0;
	state->result_idx = 0;
	state->buffer_idx = 0;
	state->found_exit_code = false;
	return (state);
}

static void	ft_handle_split(t_split_state *state, char *str)
{
	state->found_exit_code = false;
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

bool	is_exit_code(char *str, int idx)
{
	if (idx - 1 < 0)
		return (false);
	if (str[idx] == '?' && str[idx - 1] == '$')
		return (true);
	return (false);
}

char	**ft_split_on_delim(const char *str, bool(delim)(char c))
{
	t_split_state	*state;

	state = ft_init_split_state(str);
	while ((size_t)state->str_idx < (size_t)ft_strlen(str)
		&& str[state->str_idx] != '\0')
	{
		if ((!delim(str[state->str_idx]) || is_exit_code((char *)str,
					state->str_idx)) && !state->found_exit_code)
		{
			if (is_exit_code((char *)str, state->str_idx))
				state->found_exit_code = true;
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
	ft_free(state->buffer);
	state->result[state->result_idx] = NULL;
	return (state->result);
}
