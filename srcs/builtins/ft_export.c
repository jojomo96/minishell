/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:40:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 13:41:34 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_putstr(char *str, int fd_out)
{
	while (*str)
	{
		if (*str == '\"' || *str == '\\' || *str == '$')
			ft_putchar_fd('\\', fd_out);
		ft_putchar_fd(*str, fd_out);
		str++;
	}
}

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
			export_putstr(split[1], fd_out);
			ft_putstr_fd("\"\n", fd_out);
		}
		else
			ft_putstr_fd("\n", fd_out);
		i++;
		ft_strarr_free(split);
	}
}

static int	export_error(char *entry, int pos, bool print_error)
{
	(void)pos;
	if (!ft_valid_env_key(entry))
	{
		if (entry[0] == '-')
		{
			if (print_error)
				ft_print_error_env("invalid option", "export", entry);
			return (2);
		}
		if (print_error)
			ft_print_error_env("not a valid identifier", "export", entry);
		return (1);
	}
	return (0);
}

static int	ft_export_plus(t_shell *ms, char *entry)
{
	int		i;
	char	*value;
	char	*old_value;

	i = 0;
	while (entry[i] && entry[i] != '+')
		i++;
	if (entry[i + 1] != '=')
		return (ft_print_error_env(ENV_INV, "hallo", entry), 1);
	entry[i] = '\0';
	entry[i + 1] = '\0';
	value = entry + i + 2;
	old_value = ft_env_get(ms->exp, entry);
	if (old_value)
	{
		value = ft_strjoin(old_value, value);
		ft_env_set_both(ms, entry, value);
		free(value);
	}
	else
		ft_env_set_both(ms, entry, value);
	return (0);
}

int	ft_export(t_shell *ms, char **argv, int fd_out)
{
	int	i;
	int	pos;

	debug_message("executing builtin: export");
	if (argv[1] == NULL)
		return (ft_export_print(ms->exp, fd_out), 0);
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
		{
			pos = ft_env_split(argv[i]);
			if (pos == -1)
				return (ft_export_plus(ms, argv[i]));
			if (export_error(argv[i], pos, true))
				return (export_error(argv[i], pos, false));
			ft_env_set_both(ms, argv[i], argv[i] + pos);
		}
		else if (!ft_valid_env_key(argv[i]))
			return (ft_print_error_env(ENV_INV, "export", argv[i]), 1);
		else
			ft_env_set(&ms->exp, argv[i], NULL);
		i++;
	}
	return (0);
}
