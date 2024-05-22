# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:59:27 by flfische          #+#    #+#              #
#    Updated: 2024/05/22 11:06:23 by jmoritz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
MAKEFLAGS += --no-print-directory
NAME := minishell
# DIRECTORIES
SRC_DIRS := srcs \
			srcs/builtins \
			srcs/utils \
			srcs/env \
			srcs/errors \
			srcs/gcollector \
			srcs/ast \
			srcs/ast/operations \
			srcs/shell \
			srcs/execution \
			srcs/signals \
			srcs/history \


SRC_DIRS += srcs/debug

OBJ_DIR := obj
INC_DIR := includes

# FILES
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIR)

CFILES := \
		minishell.c \

# BUILTINS
CFILES += ft_pwd.c \
			ft_env.c \
			ft_cd.c \
			ft_unset.c \
			ft_export.c \
			ft_echo.c \
			ft_exit.c \
			ft_is_builtin.c \

# ENVIRONMENT
CFILES += ft_env_index.c \
			ft_env_add.c \
			ft_env_change.c \
			ft_env_create_entry.c \
			ft_env_remove.c \
			ft_env_get.c \
			ft_env_init.c \
			ft_valid_env_key.c \
			ft_env_set.c \
			ft_env_set_both.c \

# SHELL UTILS
CFILES += ft_shell_destroy.c \
			ft_shell_init.c \
			ft_shell_static.c \

# UTILS
CFILES += ft_strarr_cpy.c \
			ft_strarr_free.c \
			ft_realloc.c \
			ft_strndup.c \
			ft_isquoted.c \
			ft_strarr_sort.c \
			ft_isdir.c \
			ft_strarr_len.c \
			ft_split_on_delim.c \
			ft_strarr_join.c \
			ft_handle_quotes.c \

# ERRORS
CFILES += ft_print_error.c

# GCOLLECTOR
CFILES += ft_malloc.c \
			ft_free.c \
			ft_gc_add.c \
			ft_gc_freeall.c \
			ft_gc_set.c \
			ft_gc_get.c \

# AST
CFILES += ft_ast_create.c \
			ft_ast_utils.c \
			ft_tokenizer.c \
			ft_split_args.c \
			ft_ast_build.c \
			ft_ast_percendence.c \

# AST OPPERATIONS
CFILES += ft_ast_move_arguments.c \
			ft_traverse_and_process.c \
			ft_expand_arguments.c \
			ft_expand_wildcard.c \

# EXECUTION
CFILES += ft_execute.c \
			ft_exec_builtin.c \
			ft_exec_command.c \
			ft_exec_leaf.c \
			ft_exec_operator.c \
			ft_redirect.c \
			ft_wait.c \
			ft_exec_pipe.c \

# DEBUG
CFILES += debug_printgc.c \
			ft_debug_ast.c \
			debug_message.c \
			debug_print_node.c \

# SIGNALS
CFILES += ft_signals.c \
			ft_handler_heredoc.c \
			ft_handler_normal.c \

# HISTORY
CFILES += ft_history.c \

OFILES := $(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))

HEADER_FILES := minishell.h \
				ast.h \
				builtins.h \
				debug.h \
				environment.h \
				errors.h \
				gcollector.h \
				shellutils.h \
				utils.h \
				execution.h \
				colors.h \
				signals.h \
				history.h \

HEADER = $(addprefix $(INC_DIR)/, $(HEADER_FILES))

INCLUDES := -I$(INC_DIR)

# LIBFT

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft
INCLUDES += -I$(LIBFT_DIR)

# RULES
all: ascii $(NAME)

$(NAME): $(LIBFT) $(OFILES)
	@printf "\n$(YELLOW)Compiling $(NAME)...$(NC)\n"
	@$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS) -lreadline
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)$(NAME) compiled successfully!$(NC)"; \
		echo "$(CYAN)Run with ./$(NAME)$(NC)"; \
		echo "------------------------------------------------"; \
	else \
		echo "$(RED)$(NAME) failed to compile$(NC)"; \
	fi

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(ITALIC_LIGHT_YELLOW)$<$(NC) "
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)Creating obj directory...$(NC)"
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Removing binary files...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Removing history file...$(NC)"
	@rm -f .minishell_history

re: fclean all

norm:
	@norminette $(SRC_DIRS) $(INC_DIR) $(LIBFT_DIR) | grep "Error" || echo "$(GREEN)Norme OK$(NC)"

.PHONY: all clean fclean re norm ascii

# colors:
GREEN = \033[0;32m
LIGHT_GREEN = \033[0;92m
RED = \033[0;31m
YELLOW = \033[0;33m
LIGHT_YELLOW = \033[0;93m
ITALIC_LIGHT_YELLOW = \033[3;93m
CYAN = \033[0;36m
NC = \033[0m
CLEAR_LINE = \033[2K\r
ASCII_ART = $(CYAN)

# decoration:
ascii:
	@echo "------------------------------------------------"
	@echo "$(CYAN)"
	@echo "           __     __       "
	@echo "|\/|||\ ||(_ |__||_ |  |   "
	@echo "|  ||| \||__)|  ||__|__|__ "
	@echo "                           "
	@echo "$(NC)"

BAR_WIDTH = 50
TOTAL_SRCS = $(words $(CFILES))
