# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 19:54:07 by juyojeon          #+#    #+#              #
#    Updated: 2023/08/05 22:28:26 by juyojeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
STD_FLAG = -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
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