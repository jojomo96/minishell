/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:40:38 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 18:06:58 by jmoritz          ###   ########.fr       */
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
void					*ft_gc_safe(void *address);

#endif
