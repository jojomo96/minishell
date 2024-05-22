/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/22 15:46:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	isDelimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '*' && c != '.' );
}

static void	ft_handel_env_variable(char **str_ptr)
{
	char	*str;
	char	*new_value;

	if (str_ptr == NULL || *str_ptr == NULL)
		return ;
	str = *str_ptr;
	if (str[1] == '?')
		new_value = ft_itoa(ft_get_shell()->exit_code);
	else
		new_value = ft_fetch_env_var(str + 1);
	free(str);
	if (new_value != NULL)
		*str_ptr = new_value;
	else
		*str_ptr = NULL;
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
		if (splited_args[i][0] == '$' && !in_s_quotes
			&& splited_args[i][1] != '\0')
			ft_handel_env_variable(&splited_args[i]);
		else if (splited_args[i][0] == '~' && !in_s_quotes && !in_d_quotes)
		{
			free(splited_args[i]);
			splited_args[i] = ft_fetch_env_var("HOME");
		}
		i++;
	}
	i = 0;
	while (splited_args[i] && ft_strnstr(splited_args[i], "*", ft_strlen(splited_args[i])) != NULL)
		expand_wildcard(&splited_args[i++]);
}

static char	**ft_expand_arguments_in_strarr(char **arr)
{
	char	**splited_args;
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		splited_args = ft_split_on_delim(arr[i], &isDelimiter);
		j = 0;
		while (splited_args[j])
		{
			if (DEBUG)
				printf("DEBUG splited arguments[%d]: %s\n", j, splited_args[j]);
			j++;
		}
		ft_expand_splited_args(splited_args);
		ft_remove_outer_quotes(splited_args);
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
