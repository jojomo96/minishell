/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 15:22:29 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_env_variable(char **str_ptr, bool in_d_quotes,
		bool is_last_arg)
{
	char	*str;
	char	*new_value;

	if (str_ptr == NULL || *str_ptr == NULL)
		return ;
	str = *str_ptr;
	if (str[1] == '\0' && !in_d_quotes && !is_last_arg)
		new_value = ft_gc_safe(ft_strdup(""));
	else if (str[1] == '\0' && (in_d_quotes || is_last_arg))
		new_value = ft_gc_safe(ft_strdup("$"));
	else if (str[1] == '?')
		new_value = ft_gc_safe(ft_itoa(ft_get_shell()->exit_code));
	else if (str[1] == '/')
		new_value = ft_gc_safe(ft_strdup("$/"));
	else
		new_value = ft_fetch_env_var(str + 1);
	ft_free(str);
	if (new_value != NULL)
		*str_ptr = new_value;
	else
		*str_ptr = ft_gc_safe(ft_strdup(""));
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
		{
			ft_handle_env_variable(&splited_args[i], in_d_quotes, splited_args[i
				+ 1] == NULL);
			ft_encase_outer_quotes_in_array(&splited_args[i]);
		}
		else if (splited_args[i][0] == '~' && !in_s_quotes && !in_d_quotes
			&& splited_args[i][1] == '\0')
		{
			ft_free(splited_args[i]);
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
	ft_split_on_space(&arr, false);
	ft_expand_wildcard(arr);
	ft_split_on_space(&arr, true);
	ft_remove_outer_quotes_in_array(&arr);
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
