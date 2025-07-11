NAME = RPN
C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3	
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(C++) $(CPPFLAGS) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all