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
SRCS = ft_printf.c ft_libft.c ft_abstoa.c ft_ulltox.c
OBJS = $(SRCS:.c=.o)
SRCS_MANDATORY = ./mandatory/ft_process_print.c ./mandatory/ft_write_format.c
ORCS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS = ./bonus/ft_1_process_print_bonus.c ./bonus/ft_2_make_struct_bonus.c \
./bonus/ft_3_char_string_bonus.c ./bonus/ft_4_integer_bouns.c \
./bonus/ft_5_unsigned_int_bonus.c ./bonus/ft_6_16base_bonus.c \
./bonus/ft_7_write_ptr_bonus.c
OBJS_BOUNS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS) $(OBJS_BOUNS)
	ar -rcs $@ $(OBJS) $(OBJS_BOUNS)
else
$(NAME): $(OBJS) $(ORCS_MANDATORY)
	ar -rcs $@ $(OBJS) $(ORCS_MANDATORY)
endif

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I . -I ./bonus
else
%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I . -I ./mandatory
endif

clean :
	rm -f $(OBJS) $(ORCS_MANDATORY) $(OBJS_BOUNS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re