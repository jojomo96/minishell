/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_variables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 14:30:12 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	(void)name;
	return ("TEST_ENV");
}

// static char	*ft_expand_single_env_variable(char *env_var)
// {
// 	char **new_args;

// 	new_args = ft_split_multi(env_var, " $");

// 	env_var = ft_getenv(env_var + 1);
// 	if (env_var == NULL)
// 		env_var = ft_strdup("");
// 	return (env_var);
// }

// static char *ft_expand_env_variable(char *env_var)
// {
// 	char	*new_env_var;
// 	char	*expanded_env_var;
// 	int		i;
// 	int		j;

// 	new_env_var = ft_strdup(env_var);
// 	if (new_env_var == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (new_env_var[i])
// 	{
// 		if (new_env_var[i] == '$')
// 		{
// 			expanded_env_var = ft_expand_single_env_variable(new_env_var + i);
// 			if (expanded_env_var == NULL)
// 				expanded_env_var = ft_strdup("");
// 			j = 0;
// 			while (expanded_env_var[j])
// 			{
// 				new_env_var[i + j] = expanded_env_var[j];
// 				j++;
// 			}
// 			free(expanded_env_var);
// 		}
// 		i++;
// 	}
// 	return (new_env_var);
// }

bool	isDelimiter(char c)
{
	return (!ft_isalnum(c) && !ft_isdigit(c) && c != '_' && c != '?');
}

static char	**ft_expand_env_variables_in_strarr(char **arr)
{
	char	**new_arr;
	int		i;

	new_arr = ft_strarr_cpy(arr);
	if (new_arr == NULL)
		return (NULL);
	i = 0;
	while (new_arr[i])
	{
		int count;
		char **test = splitString(new_arr[i], &isDelimiter, &count);
		while(test && *test)
			printf("test: %s\n", *test++);
		i++;
	}
	return (new_arr);
}

void	ft_expand_env_variables(t_ast_node *node)
{
	if (node->type != AST_TYPE_LEAF)
		return ;
	if (node->u_data.leaf.argv == NULL)
		return ;
	node->u_data.leaf.argv = ft_expand_env_variables_in_strarr(node->u_data.leaf.argv);
}
