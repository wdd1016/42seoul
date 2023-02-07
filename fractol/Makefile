# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 12:40:00 by juyojeon          #+#    #+#              #
#    Updated: 2023/02/07 16:39:47 by juyojeon         ###   ########.fr        #
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

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BOUNS)
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS_BOUNS) -o $@
else
$(NAME): $(OBJS)
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $@
endif

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
