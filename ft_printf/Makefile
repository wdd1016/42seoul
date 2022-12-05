# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2022/12/05 21:11:30 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa.c ft_utoa.c ft_strchr.c ft_strlen.c \
ft_utobx.c ft_utosx.c ft_ulltox.c
OBJS = $(SRCS:.c=.o)
SRCS_MANDATORY = ./mandatory/ft_process_print.c ./mandatory/ft_write_format.c \
./mandatory/ft_wrtie_format_un.c
ORCS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS = ./bonus/ft_make_struct_bonus.c ./bonus/ft_process_print_bonus.c \
./bonus/ft_write_format_bonus.c ./bonus/ft_write_format_un_bonus.c
OBJS_BOUNS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

ifeq ($(MAKECMDGOALS), bonus)
$(NAME): $(OBJS) $(OBJS_BOUNS)
	ar -rcs $@ $(OBJS) $(OBJS_BOUNS)
else
$(NAME): $(OBJS) $(ORCS_MANDATORY)
	ar -rcs $@ $(OBJS) $(ORCS_MANDATORY)
endif

ifeq ($(MAKECMDGOALS), bonus)
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