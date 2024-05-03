#ifndef FT_AST_H
# define FT_AST_H

#define TOKEN_BUFFER_SIZE 1024

typedef enum{
  NODE_ARGUMENT,    // Represents an argument to a command
  NODE_PIPE,    // Represents a pipeline (|) between commands
  NODE_REDIRECT_IN, // Represents input redirection (<)
  NODE_REDIRECT_OUT, // Represents output redirection (>)
  NODE_APPEND_OUT,  // Represents appending output redirection (>>)
  NODE_HEREDOC,     // Represents here-document (<<)
  NODE_SUBSHELL,    // Represents a subshell group (commands enclosed in parentheses)
  NODE_AND, // Represents conditional execution (&&)
  NODE_OR,  // Represents conditional execution (||)
} e_token_type;

typedef struct s_token
{
  e_token_type type;
  char *content;
} t_token;

typedef struct s_ast_node
{
  e_token_type type;
  char *content;
  struct s_ast_node *left;
  struct s_ast_node *right;
} t_ast_node;

t_token ** ft_tokenize_input(char *input);

#endif
