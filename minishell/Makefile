# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 22:12:33 by juyojeon          #+#    #+#              #
#    Updated: 2024/08/26 21:41:11 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAG = -Wall -Wextra -Werror -g

INC = -I./includes/

R_FLAG =  -lreadline -L${HOME}/.brew/opt/readline/lib

RM = rm -f

R_INC = -I${HOME}/.brew/opt/readline/include

SRC = main.c ./parse/build_tree.c ./parse/dpp_token.c ./parse/expansion.c \
	./parse/heredoc.c ./parse/init_env.c ./parse/parse.c \
	./parse/redirect_token.c ./parse/symbol_process.c ./parse/token_node.c \
	./parse/tokenize.c \
	./utils/char_util.c ./utils/release.c ./utils/signal_handler.c \
	./utils/signal.c ./utils/split_util.c ./utils/string_util1.c \
	./utils/string_util2.c ./utils/wrapper_util.c

SRC_DIR = ./srcs/

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