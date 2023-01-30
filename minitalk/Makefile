# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 02:39:58 by juyojeon          #+#    #+#              #
#    Updated: 2023/01/30 00:09:39 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
SRCS_S = 
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C = 
OBJS_C = $(SRCS_C:.c=.o)
SRCS_BOUNS = 
OBJS_BOUNS = $(SRCS_BOUNS_S:.c=.o)

all : $(NAME_S) $(NAME_C)

bonus : $(NAME_S) $(NAME_C)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME_S): $(OBJS_S) $(OBJS_BOUNS)
	cc $(CFLAGS) $(OBJS_S) $(OBJS_BOUNS) -o $@
else
$(NAME_S): $(OBJS_S)
	cc $(CFLAGS) $(OBJS_S) -o $@
endif

$(NAME_C): $(OBJS_C)
	cc $(CFLAGS) $(OBJS_C) -o $@

%.o : %.c
	cc -c $(CFLAGS) $< -o $@ -I .

clean :
	rm -f $(OBJS_S) $(OBJS_BOUNS_S) $(OBJS_C) $(OBJS_BOUNS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : fclean all

.PHONY : all bonus clean fclean re
