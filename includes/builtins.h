/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:36 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 14:11:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_shell	t_shell;

int						ft_pwd(int fd_out);
int						ft_env(t_shell *ms, int fd_out);
int						ft_cd(t_shell *ms, char *path, int fd_out);
int						ft_unset(t_shell *ms, char **argv);
int						ft_export(t_shell *ms, char **argv, int fd_out);
int						ft_echo(char **argv, int fd_out);

// TODO:
// ft_exit

#endif
