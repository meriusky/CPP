CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = unnecessary_violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
