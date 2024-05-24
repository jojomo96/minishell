/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:40:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/24 18:11:10 by flfische         ###   ########.fr       */
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

static int	export_error(char **tmp, bool print_error)
{
	if (!tmp)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (!ft_valid_env_key(tmp[0]))
	{
		if (tmp[0] && tmp[0][0] == '-')
		{
			if (print_error)
				ft_print_error_env("invalid option", "export", tmp[0]);
			return (2);
		}
		if (print_error)
			ft_print_error_env("not a valid identifier", "export", tmp[0]);
		return (1);
	}
	return (0);
}

int	ft_export(t_shell *ms, char **argv, int fd_out)
{
	int		i;
	char	**tmp;

	debug_message("executing builtin: export");
	if (argv[1] == NULL)
		return (ft_export_print(ms->exp, fd_out), 0);
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
		{
			tmp = ft_split(argv[i], '=');
			if (export_error(tmp, true))
				return (ft_strarr_free(tmp), export_error(tmp, false));
			ft_env_set_both(ms, tmp[0], tmp[1]);
			ft_strarr_free(tmp);
		}
		else if (!ft_valid_env_key(argv[i]))
			return (ft_print_error_env("not a valid identifier", "export",
					argv[i]), 1);
		else
			ft_env_set(&ms->exp, argv[i], NULL);
		i++;
	}
	return (0);
}
