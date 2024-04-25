/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:10:22 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 00:59:10 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# include <limits.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32767
# endif

char	*get_next_line(int fd);

#endif
