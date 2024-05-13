/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_variables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 15:29:44 by jmoritz          ###   ########.fr       */
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
		char **test = ft_split_on_delim(new_arr[i], &isDelimiter);
		while(test && *test)
			printf("test: %s\n", *test++);
		printf("\n");
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
