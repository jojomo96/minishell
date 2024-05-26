/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:40:38 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 12:08:37 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCOLLECTOR_H
# define GCOLLECTOR_H

# include "minishell.h"

typedef struct s_memblock
{
	void				*address;
	struct s_memblock	*next;
}						t_memblock;

void					*ft_malloc(size_t size);
void					ft_free(void *address);
t_memblock				**ft_gc_get(void);
void					ft_gc_set(t_memblock *new_head);
void					ft_gc_add(void *address);
void					ft_gc_freeall(void);
void					*ft_gc_add_safe(void *address);

// DEBUG
void					ft_gc_debug_print(void);

#endif
