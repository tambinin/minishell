NAME = minishell
NAME_B = minishell_bonus
CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I include -I $(LIBFT_DIR)/include
	
SRCS =	srcs/main.c srcs/signal.c srcs/free_all.c \
		srcs/lexing/tokenisation.c srcs/lexing/lexers.c srcs/lexing/stock_args.c srcs/lexing/lexing_utils.c srcs/lexing/type_args.c srcs/lexing/remove_and_expand.c \
		srcs/lexing/move_quote.c srcs/lexing/lexing_utils_two.c srcs/lexing/remove_and_expand_two.c \
		srcs/lexing/stock_args_utils.c srcs/lexing/tokenisation_two.c \
		srcs/lexing/type_args_two.c srcs/lexing/type_args_three.c \
		srcs/executions/executions.c srcs/executions/execution_with_pipe.c srcs/executions/execution_utils.c srcs/executions/executions_utils_supp.c\
		srcs/executions/execution_simple_cmd.c \
		srcs/executions/parsing_command_simple.c srcs/executions/parsing_cmd_simple_utils.c \
		srcs/executions/execute_cmd_simple.c srcs/executions/execute_cmd_simple_utils.c srcs/executions/all_exec_state.c srcs/executions/check_stdin_stdout.c\
		srcs/executions/path_not_set.c srcs/executions/path_not_bin.c srcs/executions/path_not_bin_utils.c\
		srcs/executions/executions_utils_supp_two.c  \
		srcs/executions/executions_loop.c \
		srcs/executions/proccess_execution_pipe.c srcs/executions/execute_pipe_util_fourth.c\
		srcs/executions/execute_heredoc_blt.c srcs/executions/loop_heredoc_blt.c srcs/executions/parsing_arg_builtins_two.c \
		srcs/executions/parsing_arg_builtins_utils.c srcs/executions/parsing_arg_builtins.c \
		srcs/executions/execution_pipe_utils_second.c srcs/executions/execution_pipe_utils.c srcs/executions/execute_piped_commands.c\
		srcs/executions/execution_pipe_util_third.c srcs/executions/execute_pipe_util_five.c srcs/executions/execute_pipe_process_utils.c\
		srcs/executions/execute_command_pipe_utils.c srcs/executions/execution_built_pipe.c\
		srcs/syntax/syntax.c srcs/syntax/syntax_utils.c srcs/syntax/syntax_utils_two.c srcs/syntax/syntax_utils_three.c srcs/utils_functions.c \
		srcs/env_list.c srcs/signal_part_two.c\
		srcs/redirections/execute_heredoc_expand.c srcs/redirections/expand_heredoc.c srcs/redirections/expand_heredoc_utils.c\
		srcs/redirections/heredoc_pipe_utils.c \
		srcs/redirections/loop_heredoc_simple.c srcs/redirections/heredoc.c srcs/redirections/heredoc_simple_utils.c \
		srcs/redirections/redirections.c srcs/redirections/redirection_exec.c srcs/redirections/redirections_exec_pipe.c\
		srcs/redirections/redirections_with_pipe.c srcs/redirections/heredoc_with_pipe.c \
		srcs/builtins/builtins_cd.c srcs/builtins/builtins_echo.c srcs/builtins/builtins_pwd.c \
		srcs/builtins/builtins_exit.c srcs/builtins/builtins_export.c srcs/builtins/builtins_unset.c \
		srcs/builtins/builtins_utils.c srcs/builtins/builtins_env.c \
		srcs/builtins/free_memory.c srcs/lexing/wildcards.c srcs/executions/add_value_wd.c
SRCS_B = srcs/bonus/main_bonus.c srcs/bonus/signal_bonus.c srcs/bonus/free_all_bonus.c \
		srcs/bonus/lexing/tokenisation_bonus.c srcs/bonus/lexing/lexers_bonus.c srcs/bonus/lexing/stock_args_bonus.c srcs/bonus/lexing/lexing_utils_bonus.c srcs/bonus/lexing/type_args_bonus.c srcs/bonus/lexing/remove_and_expand_bonus.c \
		srcs/bonus/lexing/move_quote_bonus.c srcs/bonus/lexing/lexing_utils_two_bonus.c srcs/bonus/lexing/remove_and_expand_two_bonus.c \
		srcs/bonus/lexing/stock_args_utils_bonus.c srcs/bonus/lexing/tokenisation_two_bonus.c \
		srcs/bonus/lexing/type_args_two_bonus.c srcs/bonus/lexing/type_args_three_bonus.c \
		srcs/bonus/executions/executions_bonus.c srcs/bonus/executions/execution_with_pipe_bonus.c srcs/bonus/executions/execution_utils_bonus.c srcs/bonus/executions/executions_utils_supp_bonus.c \
		srcs/bonus/executions/execution_simple_cmd_bonus.c \
		srcs/bonus/executions/parsing_command_simple_bonus.c srcs/bonus/executions/parsing_cmd_simple_utils_bonus.c \
		srcs/bonus/executions/execute_cmd_simple_bonus.c srcs/bonus/executions/execute_cmd_simple_utils_bonus.c srcs/bonus/executions/all_exec_state_bonus.c srcs/bonus/executions/check_stdin_stdout_bonus.c \
		srcs/bonus/executions/path_not_set_bonus.c srcs/bonus/executions/path_not_bin_bonus.c srcs/bonus/executions/path_not_bin_utils_bonus.c \
		srcs/bonus/executions/executions_utils_supp_two_bonus.c \
		srcs/bonus/executions/executions_loop_bonus.c \
		srcs/bonus/executions/proccess_execution_pipe_bonus.c srcs/bonus/executions/execute_pipe_util_fourth_bonus.c \
		srcs/bonus/executions/execute_heredoc_blt_bonus.c srcs/bonus/executions/loop_heredoc_blt_bonus.c srcs/bonus/executions/parsing_arg_builtins_two_bonus.c \
		srcs/bonus/executions/parsing_arg_builtins_utils_bonus.c srcs/bonus/executions/parsing_arg_builtins_bonus.c \
		srcs/bonus/executions/execution_pipe_utils_second_bonus.c srcs/bonus/executions/execution_pipe_utils_bonus.c srcs/bonus/executions/execute_piped_commands_bonus.c \
		srcs/bonus/executions/execution_pipe_util_third_bonus.c srcs/bonus/executions/execute_pipe_util_five_bonus.c srcs/bonus/executions/execute_pipe_process_utils_bonus.c \
		srcs/bonus/executions/execute_command_pipe_utils_bonus.c srcs/bonus/executions/execution_built_pipe_bonus.c \
		srcs/bonus/syntax/syntax_bonus.c srcs/bonus/syntax/syntax_utils_bonus.c srcs/bonus/syntax/syntax_utils_two_bonus.c srcs/bonus/syntax/syntax_utils_three_bonus.c srcs/bonus/utils_functions_bonus.c \
		srcs/bonus/env_list_bonus.c srcs/bonus/signal_part_two_bonus.c \
		srcs/bonus/redirections/execute_heredoc_expand_bonus.c srcs/bonus/redirections/expand_heredoc_bonus.c srcs/bonus/redirections/expand_heredoc_utils_bonus.c \
		srcs/bonus/redirections/heredoc_pipe_utils_bonus.c \
		srcs/bonus/redirections/loop_heredoc_simple_bonus.c srcs/bonus/redirections/heredoc_bonus.c srcs/bonus/redirections/heredoc_simple_utils_bonus.c \
		srcs/bonus/redirections/redirections_bonus.c srcs/bonus/redirections/redirection_exec_bonus.c srcs/bonus/redirections/redirections_exec_pipe_bonus.c \
		srcs/bonus/redirections/redirections_with_pipe_bonus.c srcs/bonus/redirections/heredoc_with_pipe_bonus.c \
		srcs/bonus/builtins/builtins_cd_bonus.c srcs/bonus/builtins/builtins_echo_bonus.c srcs/bonus/builtins/builtins_pwd_bonus.c \
		srcs/bonus/builtins/builtins_exit_bonus.c srcs/bonus/builtins/builtins_export_bonus.c srcs/bonus/builtins/builtins_unset_bonus.c \
		srcs/bonus/builtins/builtins_utils_bonus.c srcs/bonus/builtins/builtins_env_bonus.c \
		srcs/bonus/builtins/free_memory_bonus.c srcs/bonus/lexing/wildcards_bonus.c srcs/bonus/executions/add_value_wd_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_B:.c=.o)
all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(NAME_B)
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L/usr/local/lib -I/usr/local/include -lreadline -o $(NAME) 
$(NAME_B): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -L/usr/local/lib -I/usr/local/include -lreadline -o $(NAME_B) 

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -L/usr/local/lib -I/usr/local/include -lreadline -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
