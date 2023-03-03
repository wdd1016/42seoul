# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:57:37 by juyojeon          #+#    #+#              #
#    Updated: 2023/03/03 21:52:32 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = ./srcs/philo.c ./srcs/initialization.c ./srcs/threadroutine.c \
./srcs/flagprint.c ./srcs/functions.c
OBJS = $(SRCS:.c=.o)
# SRCS_BONUS = ./bonus/
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

# bonus : $(NAME)

# ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
# $(NAME): $(OBJS_BONUS)
# 	cc $(CFLAGS)  $(OBJS_BONUS) -o $@
# else
$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@
# endif

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
# $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
