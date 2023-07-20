# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 17:26:35 by juyojeon          #+#    #+#              #
#    Updated: 2023/07/20 23:01:51 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
STD_FLAG = -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(STD_FLAG) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(STD_FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re