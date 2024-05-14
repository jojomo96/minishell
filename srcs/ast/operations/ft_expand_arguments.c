/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 09:39:40 by jmoritz          ###   ########.fr       */
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
	return (!ft_isalnum(c) && c != '_');
}

static void	ft_handle_quotes(char *arr, bool *in_s_quotes, bool *in_d_quotes)
{
	if (arr == NULL || *arr == '\0')
		return ;
	if (arr[0] == '\'' && !*in_d_quotes)
	{
		if (!*in_s_quotes)
			arr[0] = '\0';
		*in_s_quotes = !*in_s_quotes;
	}
	if (arr[0] == '\"')
	{
		if (!*in_d_quotes)
			arr[0] = '\0';
		*in_d_quotes = !*in_d_quotes;
	}
}

static void	ft_handel_env_variable(char *str)
{
	if (str[1] && str[1] == '?')
	{
		free(str);
		str = ft_strdup(ft_get_exit_code());
	}
	else
	{
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
		ft_handle_quotes(splited_args[i], &in_s_quotes, &in_d_quotes);
		if (splited_args[i][0] == '$' && !in_s_quotes)
			ft_handel_env_variable(splited_args[i]);
		i++;
	}
}

static char	**ft_expand_arguments_in_strarr(char **arr)
{
	char	**splited_args;
	int		i;

	i = 0;
	while (arr[i])
	{
		splited_args = ft_split_on_delim(arr[i], &isDelimiter);
		int j = 0;
		while (splited_args[j])
		{
			if (DEBUG)
				printf("DEBUG splited arguments[%d]: %s\n", j, splited_args[j]);
			j++;
		}
		ft_expand_splited_args(splited_args);
		ft_free(arr[i]);
		arr[i] = ft_strarr_join(splited_args);
		if (DEBUG)
			printf("DEBUG expanded arguments[%d]: %s\n", i, arr[i]);
		i++;
	}
	return (arr);
}

void	ft_expand_arguments(t_ast_node *node)
{
	if (node->type != AST_TYPE_LEAF)
		return ;
	if (node->u_data.leaf.argv == NULL)
		return ;
	node->u_data.leaf.argv = ft_expand_arguments_in_strarr(node->u_data.leaf.argv);
}
