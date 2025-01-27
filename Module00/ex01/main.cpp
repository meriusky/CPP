/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:58:17 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/27 16:00:45 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>
#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

        // Read user input
        if (!std::getline(std::cin, command)) {  // Detect EOF (Ctrl+D)
            std::cout << "\nCtrl+D detected. Exiting program..." << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.AddContact();
        } else if (command == "SEARCH") {
            phoneBook.SearchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}

/*
int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.AddContact();
        } else if (command == "SEARCH") {
            phoneBook.SearchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}*/
