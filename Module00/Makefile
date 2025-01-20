# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic

# Target executable name
TARGET = toupper

# Source files
SRC = toupper.cpp

# Build rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean

