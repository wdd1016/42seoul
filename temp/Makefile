# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 23:17:46 by juyojeon          #+#    #+#              #
#    Updated: 2022/12/02 22:43:36 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa.c ft_itou.c ft_strchr.c ft_strlen.c \
ft_ulltox.c 
OBJS = $(SRCS:.c=.o)
SRCS_MANDATORY = ft_process_print.c ft_write_format.c ft_wrtie_format_un.c
ORCS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS = ft_make_struct_bonus.c ft_process_print_bonus.c 
OBJS_BOUNS = $(SRCS_BONUS:.c=.o)
INC = .

all : $(NAME)

bonus : $(NAME)

ifneq ($(MAKECMDGOALS), bonus)
$(NAME): $(OBJS) $(ORCS_MANDATORY)
	ar -rcs $@ $(OBJS) $(ORCS_MANDATORY)
else
$(NAME): $(OBJS) $(OBJS_BOUNS)
	ar -rcs $@ $(OBJS) $(OBJS_BOUNS)
endif

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I $(INC)

clean :
	rm -f $(OBJS) $(ORCS_MANDATORY) $(OBJS_BOUNS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re