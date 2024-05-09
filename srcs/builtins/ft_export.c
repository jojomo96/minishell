/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:40:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 14:09:59 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_export_print(char **exp, int fd_out)
{
	int		i;
	char	**split;

	i = 0;
	ft_strarr_sort(exp);
	while (exp[i])
	{
		split = ft_split(exp[i], '=');
		if (!split)
			return (ft_print_error(strerror(errno), NULL, NULL));
		ft_putstr_fd("declare -x ", fd_out);
		ft_putstr_fd(split[0], fd_out);
		if (split[1])
		{
			ft_putstr_fd("=\"", fd_out);
			ft_putstr_fd(split[1], fd_out);
			ft_putstr_fd("\"\n", fd_out);
		}
		else
			ft_putstr_fd("\n", fd_out);
		i++;
		ft_strarr_free(split);
	}
}

int	ft_export(t_shell *ms, char **argv, int fd_out)
{
	int		i;
	char	**tmp;

	if (argv[1] == NULL)
		return (ft_export_print(ms->exp, fd_out), 0);
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
		{
			tmp = ft_split(argv[i], '=');
			if (!tmp)
				return (ft_print_error(strerror(errno), NULL, NULL), 1);
			ft_env_set(&ms->exp, tmp[0], tmp[1]);
			ft_env_set(&ms->env, tmp[0], tmp[1]);
			ft_strarr_free(tmp);
		}
		else
			ft_env_set(&ms->exp, argv[i], NULL);
		i++;
	}
	return (0);
}
