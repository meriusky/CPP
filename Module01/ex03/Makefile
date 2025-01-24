CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target es el nom de l'executable
TARGET = zombie

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
