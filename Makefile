NAME = FILE

INCLUDE = include

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)

RM = rm -rf

HEADER = $(INCLUDE)/FileM.hpp

REPLACE = ./replace

SRC = ./main.cpp src/FileM.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@if [ ! -d $(REPLACE) ]; then mkdir -p $(REPLACE); fi
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(REPLACE)

re: fclean all

.PHONY: all clean fclean re
