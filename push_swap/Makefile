# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2023/01/26 22:32:20 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker
SRCS = ./srcs/push_swap.c ./srcs/ft_split.c ./srcs/1_make_array.c \
./srcs/2_compression.c ./srcs/3_timsort.c ./srcs/4_command.c \
./srcs/5_stackfuncion.c ./srcs/6_smallsort.c ./srcs/7_hardsort.c \
./srcs/8_qdsort.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ./bonus/checker_bonus.c ./bonus/ft_split_bonus.c \
./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
./bonus/1_make_array_bonus.c ./bonus/2_is_valid_stack_bonus.c \
./bonus/3_timsort_bonus.c ./bonus/4_stackfuncion_bonus.c \
./bonus/5_command_bonus.c ./bonus/6_play_command_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
	cc $(CFLAGS) $(OBJS_BONUS) -o $@

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I ./srcs

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
