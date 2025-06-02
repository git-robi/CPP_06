# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 12:46:17 by rgiambon          #+#    #+#              #
#    Updated: 2025/06/02 12:46:18 by rgiambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer
CXX = c++                  
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
LDFLAGS = -fsanitize=address
SOURCES = main.cpp Serializer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Serializer.hpp Data.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
