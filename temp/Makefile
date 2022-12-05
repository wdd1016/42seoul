# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2022/12/05 20:51:54 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa.c ft_utoa.c ft_strchr.c ft_strlen.c \
ft_utobx.c ft_utosx.c ft_ulltox.c
OBJS = $(SRCS:.c=.o)
SRCS_MANDATORY = ./mandatory/ft_process_print.c ./mandatory/ft_write_format.c \
./mandatory/ft_wrtie_format_un.c
ORCS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
INC = .

all : $(NAME)

$(NAME): $(OBJS) $(ORCS_MANDATORY)
	ar -rcs $@ $(OBJS) $(ORCS_MANDATORY)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I . -I ./mandatory

clean :
	rm -f $(OBJS) $(ORCS_MANDATORY)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re