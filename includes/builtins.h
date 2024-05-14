/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:36 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 15:10:58 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_shell	t_shell;

typedef enum e_builtin
{
	NONE,
	BUILTIN_ECHO,
	BUILTIN_CD,
	BUILTIN_PWD,
	BUILTIN_EXPORT,
	BUILTIN_UNSET,
	BUILTIN_ENV,
	BUILTIN_EXIT
}						t_builtin;

int						ft_pwd(int fd_out);
int						ft_env(t_shell *ms, int fd_out);
int						ft_cd(t_shell *ms, char **argv, int fd_out);
int						ft_unset(t_shell *ms, char **argv);
int						ft_export(t_shell *ms, char **argv, int fd_out);
int						ft_echo(char **argv, int fd_out);
void					ft_exit(t_shell *ms, char **argv, int fd_out);

t_builtin				ft_is_builtin(char *cmd);

#endif
