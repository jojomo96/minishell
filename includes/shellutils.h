/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellutils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:15 by flfische          #+#    #+#             */
/*   Updated: 2024/05/13 11:53:58 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUTILS_H
# define SHELLUTILS_H

# include "minishell.h"

typedef struct s_shell	t_shell;

int						ft_shell_init(t_shell *ms, char **envp);
int						ft_destroy_shell(t_shell *ms, int should_exit);
t_shell					*ft_get_shell(void);

#endif
