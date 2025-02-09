CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = ClapTrap
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp #1, 2
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
# 1: % is a pattern rule that tells makefile to create .o files
# 2: $< represent the input file and $@ represents the out file
