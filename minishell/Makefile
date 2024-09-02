# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 22:12:33 by juyojeon          #+#    #+#              #
#    Updated: 2024/09/02 19:15:37 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = -I./includes/

R_FLAG =  -lreadline -L${HOME}/.brew/opt/readline/lib

RM = rm -f

R_INC = -I${HOME}/.brew/opt/readline/include

SRC = main.c \
	./builtin/builtin.c ./builtin/cd.c ./builtin/echo.c \
	./builtin/env.c ./builtin/exit.c ./builtin/export.c \
	./builtin/pwd.c ./builtin/unset.c \
	./execute/command_exception.c ./execute/command.c \
	./execute/double_bar.c ./execute/execute.c ./execute/expansion.c \
	./execute/pipe.c ./execute/redirect.c ./execute/symbol_process.c \
	./execute/wildcard_process.c ./execute/wildcard_util.c \
	./parse/build_tree.c ./parse/env_node.c ./parse/heredoc.c \
	./parse/token_node.c ./parse/token_redirect.c ./parse/token.c \
	./parse/tokenize.c \
	./utils/char_util.c ./utils/env_util.c ./utils/error.c \
	./utils/exit_status.c ./utils/quick_sort.c ./utils/release.c \
	./utils/signal_handler.c ./utils/signal.c ./utils/split_util.c \
	./utils/string_util1.c ./utils/string_util2.c ./utils/string_util3.c \
	./utils/wrapper_directory.c ./utils/wrapper_util.c

SRC_DIR = ./srcs/
BONUS_DIR = ./bonus/

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))


all : $(NAME)

bonus : $(NAME)

.c.o:
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $^ $(R_FLAG) -o $@
	@printf	"Get Ready for the Minishell\n"
else
$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $^ $(R_FLAG) -o $@
	@printf	"Get Ready for the Minishell\n"
endif

clean :
	@$(RM) $(OBJS)
	@printf	"Run to Clean\n"

fclean :
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@printf	"Run to fClean\n"

re : fclean all

.PHONY : all clean fclean re