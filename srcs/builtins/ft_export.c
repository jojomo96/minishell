/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:40:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 16:52:36 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_print(char **exp)
{
	int		i;
	char	**split;

	i = 0;
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

int	ft_export(char ***envp, char **args)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	if (!args[0])
	{
		ft_export_print(*envp);
		return (0);
	}
	return (ret);
}
