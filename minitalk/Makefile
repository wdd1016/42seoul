# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 02:39:58 by juyojeon          #+#    #+#              #
#    Updated: 2023/02/26 18:03:12 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
SRCS_S = server.c server_func.c
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)

all : $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	cc $(CFLAGS) $(OBJS_S) -o $@

$(NAME_C): $(OBJS_C)
	cc $(CFLAGS) $(OBJS_C) -o $@

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I .

clean :
	rm -f $(OBJS_S) $(OBJS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : fclean all

.PHONY : all clean fclean re
