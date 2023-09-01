# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 12:40:00 by juyojeon          #+#    #+#              #
#    Updated: 2023/09/01 15:49:01 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
SRCS = ./srcs/
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ./bonus/f
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
