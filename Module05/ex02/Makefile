CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP

TARGET = Bureaucrat 
TREE = home_shrubbery
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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
	rm -f $(TARGET) $(TREE)

re: fclean all

.PHONY: all clean fclean re
