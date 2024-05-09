/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:15:29 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 15:05:09 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define TOKEN_BUFFER_SIZE 64

# include <stdio.h>

typedef struct s_ast_node		t_ast_node;

typedef enum e_ast_node_type
{
	AST_TYPE_LEAF,
	AST_TYPE_NODE,
	AST_TYPE_PARANTHESIS
}								t_ast_node_type;

typedef enum e_ast_paranthesis
{
	AST_PARANTHESIS_OPEN,
	AST_PARANTHESIS_CLOSE
}								t_ast_paranthesis;

typedef enum e_operation_type
{
	OP_REDIRECT_IN,
	OP_REDIRECT_OUT,
	OP_APPEND_OUT,
	OP_HEREDOC,
	OP_PIPE,
	OP_AND,
	OP_OR,
	OP_SUBSHELL
}								t_operation_type;

typedef struct s_ast_leaf
{
	char						**argv;
}								t_ast_leaf;

struct							s_ast_node
{
	t_ast_node_type				type;
	union
	{
		t_ast_leaf				leaf;
		struct
		{
			t_operation_type	op_type;
			t_ast_node			*left;
			t_ast_node			*right;
		} s_node;
		t_ast_paranthesis		type;
	} u_data;
};

t_ast_node						*ft_ast_new_node(const char *input,
									size_t start, size_t value_length);
void							ft_ast_free_node(t_ast_node *node);

t_ast_node						**ft_tokenize_input(char *input);
void							build_ast(t_ast_node **ast, t_ast_node **nodes);
int								find_highest_precedence_index(t_ast_node **nodes,
									int *is_in_parenthesis);

// utils
const char						*op_type_to_string(t_operation_type op_type);
void							write_ast_to_dot_file(t_ast_node *root);
char							**ft_split_args(char *content);

typedef struct s_iterator_split
{
	int							start;
	int							end;
	int							i;
}								t_range_split;

t_range_split					ft_create_range_split(void);

#endif
