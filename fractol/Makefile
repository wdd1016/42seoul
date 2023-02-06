# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 12:40:00 by juyojeon          #+#    #+#              #
#    Updated: 2023/02/07 01:53:00 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -O2 -Wall -Wextra -Werror
NAME = fractol
SRCS = ./srcs/fractol.c ./srcs/hooking.c ./srcs/put_print_image.c \
./srcs/shift_scaling.c ./srcs/utils.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $< -o $@

%.o : %.c
	cc $(CFLAGS) -lmix -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus