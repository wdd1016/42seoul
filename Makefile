
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 12:40:00 by juyojeon          #+#    #+#              #
#    Updated: 2023/09/14 20:20:27 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -O2 -Wall -Wextra -Werror
NAME = cub3D
SRCS = ./srcs/hook_move.c ./srcs/hook.c ./srcs/init.c ./srcs/main.c \
       ./srcs/map_coor.c ./srcs/map_validation.c ./srcs/map.c ./srcs/utils.c \
       ./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/rendering.c \
       ./srcs/texture.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ./bonus/hook_move_bonus.c ./bonus/hook_bonus.c \
             ./bonus/init_bonus.c ./bonus/main_bonus.c \
			 ./bonus/map_coor_bonus.c ./bonus/map_validation_bonus.c \
			 ./bonus/map_bonus.c ./bonus/utils_bonus.c \
			 ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
			 ./bonus/rendering_bonus.c ./bonus/texture_bonus.c \
			 ./bonus/minimap_bonus.c ./bonus/sprite_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BONUS)
	make -C mlx
	# cp mlx/libmlx.dylib .
	cp mlx/libmlx.a .
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $@
else
$(NAME): $(OBJS)
	make -C mlx
	# cp mlx/libmlx.dylib .
	cp mlx/libmlx.a .
	cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $@
endif

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	make -C mlx clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	# rm -f libmlx.dylib
	rm -f libmlx.a
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
