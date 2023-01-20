# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2023/01/20 13:09:55 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = ./srcs/push_swap.c ./srcs/ft_valid_atoi.c ./srcs/ft_split.c \
./srcs/1_make_array.c ./srcs/2_compression.c ./srcs/3_timsort.c \
./srcs/4_command.c ./srcs/5_stackfuncion.c ./srcs/6_smallsort.c \
./srcs/7_hardsort.c ./srcs/8_qdsort.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I ./srcs

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
