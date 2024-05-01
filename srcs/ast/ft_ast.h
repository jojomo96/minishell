#ifndef FT_AST_H
# define FT_AST_H

typedef enum{
  NODE_COMMAND,     // Represents a command to be executed
  NODE_ARGUMENT,    // Represents an argument to a command
  NODE_PIPELINE,    // Represents a pipeline (|) between commands
  NODE_SEQUENCE,    // Represents a sequence of commands (;)
  NODE_REDIRECT_IN, // Represents input redirection (<)
  NODE_REDIRECT_OUT, // Represents output redirection (>)
  NODE_APPEND_OUT,  // Represents appending output redirection (>>)
  NODE_HEREDOC,     // Represents here-document (<<)
  NODE_BACKGROUND,  // Represents a background job (&)
  NODE_SUBSHELL,    // Represents a subshell group (commands enclosed in parentheses)
  NODE_CONDITIONAL_AND, // Represents conditional execution (&&)
  NODE_CONDITIONAL_OR,  // Represents conditional execution (||)
  NODE_NOT,         // Represents NOT operator (!), used for logical negation
  NODE_IF,          // Represents an if statement (if condition)
  NODE_THEN,        // Represents the then block for an if statement
  NODE_ELSE,        // Represents the else block for an if statement
  NODE_FI,          // Marks the end of an if statement
  NODE_WHILE,       // Represents a while loop
  NODE_DO,          // Represents the do block of a while loop
  NODE_DONE,        // Marks the end of a while loop
  NODE_CASE,        // Represents a case statement
  NODE_IN,          // Used within a case statement to mark case entries
  NODE_ESAC,        // Marks the end of a case statement
  NODE_FUNCTION_DEF, // Represents a function definition
  NODE_FUNCTION_CALL // Represents a call to a defined function
} e_ast_node_type;

typedef struct s_ast_node
{
  e_ast_node_type type;
  char *content;
  struct s_ast_node *left;
  struct s_ast_node *right;
} t_ast_node;

#endif
