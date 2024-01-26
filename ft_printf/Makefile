# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2022/12/16 07:09:12 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ./mandatory/ft_1_printf.c ./mandatory/ft_2_print_process.c \
./mandatory/ft_3_write_format.c ./mandatory/ft_abstoa.c ./mandatory/ft_libft.c \
./mandatory/ft_ulltox.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ./bonus/ft_0_printf_bonus.c ./bonus/ft_1_print_process_bonus.c \
./bonus/ft_2_make_struct_bonus.c ./bonus/ft_3_char_string_bonus.c \
./bonus/ft_4_integer_bouns.c ./bonus/ft_5_unsigned_int_bonus.c \
./bonus/ft_6_16base_bonus.c ./bonus/ft_7_write_ptr_bonus.c \
./bonus/ft_libft_bonus.c ./bonus/ft_abstoa_bonus.c ./bonus/ft_ulltox_bonus.c

OBJS_BOUNS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BOUNS)
	ar -rcs $@ $(OBJS_BOUNS)
else
$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)
endif

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I ./bonus
else
%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I ./mandatory
endif

clean :
	rm -f $(OBJS) $(OBJS_BOUNS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re