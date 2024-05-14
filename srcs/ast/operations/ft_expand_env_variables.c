/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_variables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 08:24:00 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	(void)name;
	return ("TEST_ENV");
}

char	*ft_get_exit_code(void)
{
	return ("0");
}

bool	isDelimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '?');
}

static void	ft_handle_quotes(char c, bool *in_s_quotes, bool *in_d_quotes)
{
	if (c == '\'' && !*in_d_quotes)
		*in_s_quotes = !*in_s_quotes;
	if (c == '\"')
		*in_d_quotes = !*in_d_quotes;
}

static void	ft_handel_env_variable(char *str)
{
	if (str[1] && str[1] == '?')
	{
		free(str);
		str = ft_strdup(ft_get_exit_code());
	} else {
		free(str);
		str = ft_strdup(ft_getenv("TEST_ENV"));
	}
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
		ft_handle_quotes(splited_args[i][0], &in_s_quotes, &in_d_quotes);
		if (splited_args[i][0] == '$' && !in_s_quotes)
			ft_handel_env_variable(splited_args[i]);
		i++;
	}
}

static char	**ft_expand_env_variables_in_strarr(char **arr)
{
	char	**new_args_arr;
	char	**splited_args;
	int		i;

	new_args_arr = ft_strarr_cpy(arr);
	if (new_args_arr == NULL)
		return (NULL);
	i = 0;
	while (new_args_arr[i])
	{
		splited_args = ft_split_on_delim(new_args_arr[i], &isDelimiter);
		ft_expand_splited_args(splited_args);
		free(new_args_arr[i]);
		new_args_arr[i] = ft_strarr_join(splited_args);
		i++;
	}
	return (new_args_arr);
}

void	ft_expand_arguments(t_ast_node *node)
{
	if (node->type != AST_TYPE_LEAF)
		return ;
	if (node->u_data.leaf.argv == NULL)
		return ;
	node->u_data.leaf.argv = ft_expand_env_variables_in_strarr(node->u_data.leaf.argv);
}
