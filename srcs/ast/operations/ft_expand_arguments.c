/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 15:25:35 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO maybe remove . from is_delimiter
bool	is_delimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '*');
}

static void	ft_handle_env_variable(char **str_ptr, bool in_d_quotes,
		bool is_last_arg)
{
	char	*str;
	char	*new_value;

	if (str_ptr == NULL || *str_ptr == NULL)
		return ;
	str = *str_ptr;
	if (str[1] == '\0' && !in_d_quotes && !is_last_arg)
		new_value = ft_strdup("");
	else if (str[1] == '\0' && (in_d_quotes || is_last_arg))
		new_value = ft_strdup("$");
	else if (str[1] == '?')
		new_value = ft_itoa(ft_get_shell()->exit_code);
	else
		new_value = ft_fetch_env_var(str + 1);
	free(str);
	if (new_value != NULL)
		*str_ptr = new_value;
	else
		*str_ptr = ft_strdup("");
}

static void	ft_expand_splited_args(char **splited_args)
{
	int		i;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	i = 0;
	while (splited_args[i])
	{
		ft_toggle_quotes(splited_args[i], &in_s_quotes, &in_d_quotes);
		if (splited_args[i][0] == '$' && !in_s_quotes)
			ft_handle_env_variable(&splited_args[i], in_d_quotes, splited_args[i
				+ 1] == NULL);
		else if (splited_args[i][0] == '~' && !in_s_quotes && !in_d_quotes
			&& splited_args[i][1] == '\0')
		{
			free(splited_args[i]);
			splited_args[i] = ft_fetch_env_var("HOME");
		}
		i++;
	}
}

static char	**ft_expand_arg_in_strarr(char **arr)
{
	char	**splited_args;
	int		i;

	i = 0;
	while (arr[i])
	{
		splited_args = ft_split_on_delim(arr[i], &is_delimiter);
		debug_print_strarr(splited_args);
		ft_expand_splited_args(splited_args);
		ft_free(arr[i]);
		arr[i] = ft_strarr_join(splited_args);
		debug_message_1("Expanded argument: ", arr[i]);
		i++;
	}
	ft_split_on_space(&arr);
	ft_expand_wildcard(arr);
	ft_split_on_space(&arr);
	i = 0;
	while (arr[i] != NULL)
	{
		splited_args = ft_split_on_delim(arr[i], &is_delimiter);
		ft_remove_outer_quotes(splited_args);
		arr[i++] = ft_strarr_join(splited_args);
	}
	return (arr);
}

void	ft_expand_arguments(t_ast_node *node)
{
	if (node->type != AST_TYPE_LEAF)
		return ;
	if (node->u_data.leaf.argv == NULL)
		return ;
	node->u_data.leaf.argv = ft_expand_arg_in_strarr(node->u_data.leaf.argv);
}
