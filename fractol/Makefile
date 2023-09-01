# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 12:40:00 by juyojeon          #+#    #+#              #
#    Updated: 2023/09/01 16:46:37 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -O2 -Wall -Wextra -Werror
NAME = fractol
SRCS = ./srcs/fractol.c ./srcs/hooking.c ./srcs/put_print_image.c \
./srcs/shift_scaling.c ./srcs/utils.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ./bonus/fractol_bonus.c ./bonus/hooking_bonus.c \
./bonus/put_print_image_bonus.c ./bonus/shift_scaling_bonus.c \
./bonus/utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BONUS)
	make -C mlx
	cp mlx/libmlx.dylib .
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $@
else
$(NAME): $(OBJS)
	make -C mlx
	cp mlx/libmlx.dylib .
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $@
endif

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	make -C mlx clean
	rm libmlx.dylib
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
