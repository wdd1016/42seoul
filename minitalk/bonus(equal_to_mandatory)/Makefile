# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 02:39:58 by juyojeon          #+#    #+#              #
#    Updated: 2023/02/01 03:37:20 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
SRCS_S = server.c server_func.c
OBJS_S = $(SRCS_S:.c=.o)
SRCS_BONUS_S = server_bonus.c server_func_bonus.c
OBJS_BONUS_S = $(SRCS_BONUS_S:.c=.o)
SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)
SRCS_BONUS_C = client_bonus.c
OBJS_BONUS_C = $(SRCS_BONUS_C:.c=.o)

all : $(NAME_S) $(NAME_C)

bonus : $(NAME_S) $(NAME_C)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME_S): $(OBJS_BONUS_S)
	cc $(CFLAGS) $(OBJS_BONUS_S) -o $@

$(NAME_C): $(OBJS_BONUS_C)
	cc $(CFLAGS) $(OBJS_BONUS_C) -o $@
else
$(NAME_S): $(OBJS_S)
	cc $(CFLAGS) $(OBJS_S) -o $@

$(NAME_C): $(OBJS_C)
	cc $(CFLAGS) $(OBJS_C) -o $@
endif

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I .

clean :
	rm -f $(OBJS_S) $(OBJS_BONUS_S) $(OBJS_C) $(OBJS_BONUS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : fclean all

.PHONY : all bonus clean fclean re
