# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 02:39:58 by juyojeon          #+#    #+#              #
#    Updated: 2023/01/29 03:38:02 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
SRCS_S = 
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C = 
OBJS_C = $(SRCS_C:.c=.o)
SRCS_BOUNS_S = 
OBJS_BOUNS_S = $(SRCS_BOUNS_S:.c=.o)
SRCS_BOUNS_C = 
OBJS_BOUNS_C = $(SRCS_BOUNS_C:.c=.o)

all : $(NAME_S) $(NAME_C)

bonus : $(NAME_S) $(NAME_C)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME_S): $(OBJS_S) $(OBJS_BOUNS_S)
	cc $(CFLAGS) $(OBJS_S) $(OBJS_BOUNS_S) -o $@
else
$(NAME_S): $(OBJS_S)
	cc $(CFLAGS) $(OBJS_S) -o $@
endif

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME_C): $(OBJS_C) $(OBJS_BOUNS_C)
	cc $(CFLAGS) $(OBJS_C) $(OBJS_BOUNS_C) -o $@
else
$(NAME_C): $(OBJS_C)
	cc $(CFLAGS) $(OBJS_C) -o $@
endif

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I .

clean :
	rm -f $(OBJS_S) $(OBJS_BOUNS_S) $(OBJS_C) $(OBJS_BOUNS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : fclean all

.PHONY : all bonus clean fclean re

	