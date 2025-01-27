# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 09:59:38 by mehernan          #+#    #+#              #
#    Updated: 2025/01/27 12:51:01 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Per compilar i les flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target es el nom de l'executable
TARGET = megaphone

SRC = megaphone.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean

