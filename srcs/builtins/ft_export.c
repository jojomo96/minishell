/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:40:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 18:13:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_print(char **exp)
{
	int		i;
	char	**split;

	i = 0;
	ft_strarr_sort(exp);
	while (exp[i])
	{
		split = ft_split(exp[i], '=');
		if (!split)
		{
			ft_print_error(strerror(errno), NULL, NULL);
			return ;
		}
		if (split[1])
			printf("declare -x %s=\"%s\"\n", split[0], split[1]);
		else
			printf("declare -x %s\n", split[0]);
		i++;
		ft_strarr_free(split);
	}
}

int	ft_export(char ***envp, char ***exp, char **args)
{
	int		i;
	char	*key;
	char	*val;
	char	**tmp;

	i = 0;
	if (!args || !args[0])
		return (ft_export_print(*exp), 0);
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			tmp = ft_split(args[i], '=');
			if (!tmp)
				return (ft_print_error(strerror(errno), NULL, NULL), 1);
			key = tmp[0];
			val = tmp[1];
			ft_env_set(exp, key, val);
			ft_env_set(envp, key, val);
			free(key);
			free(val);
		}
		else
			ft_env_set(exp, args[i], NULL);
		i++;
	}
	return (0);
}
