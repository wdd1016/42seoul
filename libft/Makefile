# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:38:01 by juyojeon          #+#    #+#              #
#    Updated: 2022/11/11 15:36:08 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_*.c
OBJS = $(SRCS:.c=.o)
INC = includes

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean