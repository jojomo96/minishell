/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:47 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 08:14:53 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* INCLUDES */
# include "../libft/libft.h"
# include "ast.h"
# include "builtins.h"
# include "debug.h"
# include "environment.h"
# include "errors.h"
# include "gcollector.h"
# include "utils.h"
/* EXTERNAL INCLUDES */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


# ifndef DEBUG
#  define DEBUG 1
# endif

# define SHELL_NAME "minishell"

#endif
