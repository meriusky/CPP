CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target is the name of the executable
TARGET = hi_this_is_brain

SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
