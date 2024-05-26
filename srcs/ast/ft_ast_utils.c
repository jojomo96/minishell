/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:45:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 17:38:44 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*op_type_to_string(t_operation_type op_type)
{
	int			num_op_types;
	const char	*op_type_strings[] = {"<", ">", ">>", "<<", "|", "&&", "||"};

	num_op_types = sizeof(op_type_strings) / sizeof(op_type_strings[0]);
	if ((int)op_type >= num_op_types)
	{
		return ("UNKNOWN_OP");
	}
	return (op_type_strings[op_type]);
}
