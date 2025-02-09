CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP

TARGET = ClapTrap
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) 

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
