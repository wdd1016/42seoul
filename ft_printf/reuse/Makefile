# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2023/01/29 02:28:52 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_abstoa.c ft_ulltox.c ft_write_format.c
OBJS = $(SRCS:.c=.o)
INC = .

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I .

clean :
	rm -f $(OBJS) $(ORCS_MANDATORY)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re