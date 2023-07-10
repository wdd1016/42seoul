# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 17:25:47 by juyojeon          #+#    #+#              #
#    Updated: 2023/07/10 23:48:49 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Replace
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
STD_FLAG = -std=c++98

SRC = main.cpp Replace.cpp
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