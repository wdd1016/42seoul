# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 22:12:33 by juyojeon          #+#    #+#              #
#    Updated: 2024/08/14 22:15:21 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = -I./includes/

R_FLAG =  -lreadline -L${HOME}/.brew/opt/readline/lib

RM = rm -f

R_INC = -I${HOME}/.brew/opt/readline/include

LIB_FLAG = -Llib -lft

SRC =	main.c

SRC_DIR = ./srcs/

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))


all : $(NAME)

bonus : $(NAME)

.c.o:
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS)
	@make -C lib
	@$(CC) $(CFLAG) $^ $(LIB_FLAG) $(R_FLAG) -o $@
	@printf	"Get Ready for the Minishell\n"
else
$(NAME): $(OBJS)
	@make -C lib
	@$(CC) $(CFLAG) $^ $(LIB_FLAG) $(R_FLAG) -o $@
	@printf	"Get Ready for the Minishell\n"
endif

clean :
	@make clean -C lib
	@$(RM) $(OBJS)
	@printf	"Run to Clean\n"

fclean :
	@make fclean -C lib
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@printf	"Run to fClean\n"

re : fclean all

.PHONY : all clean fclean re