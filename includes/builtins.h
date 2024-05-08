/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:36 by flfische          #+#    #+#             */
/*   Updated: 2024/05/07 14:50:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_shell	t_shell;

int						ft_pwd(void);
int						ft_env(char ***envp);
int						ft_cd(char ***env, char *path);
int						ft_unset(t_shell *ms, char **keys);
int						ft_export(char ***env, char ***exp, char **args);

// TODO:
// ft_echo
// ft_cd
// ft_export
// ft_unset
// ft_exit

#endif
