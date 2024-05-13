/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_variables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 16:38:04 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	(void)name;
	return ("TEST_ENV");
}

bool	isDelimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '?');
}

static void ft_handle_splited_args(char **splited_args)
{
	int		s_counter;

	s_counter = 0;
	while (splited_args[s_counter])
	{
		if (splited_args[s_counter][0] == '$')
		{
			free(splited_args[s_counter]);
			splited_args[s_counter] = ft_strdup(ft_getenv("TEST_ENV"));
		}
		s_counter++;
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
		int y = 0;
		while (splited_args[y])
		{
			printf("splited_args[%d]: %s\n", y, splited_args[y]);
			y++;
		}

		ft_handle_splited_args(splited_args);
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
