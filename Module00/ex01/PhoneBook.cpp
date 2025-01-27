/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:58:42 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/27 16:00:43 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <string>
#include <stdexcept>
#include <sstream>
//Que es std::cin?
//std::cin (character input)nos permite acceptar datos a traves del teclado.
//>> es el operador extractor, extrae los datos de std::cin y los guarda en una variable
PhoneBook::PhoneBook() : _index(0), _count(0){}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destroyed. Goodbye!\n";
}

void PhoneBook::AddContact() {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    _contacts[_index].SetContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

    std::cout << "Contact added successfully!\n";
    _index = (_index + 1) % 8; // Wrap around if the phone book is full
	if(_count < 8)
		_count++;
}
void PhoneBook::SearchContacts() const
{
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < _count; ++i)
	{
        _contacts[i].DisplayShort(i);
    }

    std::cout << "\nEnter the index of the contact to view details: ";
	std::string str;
	int index;
	int i = 1;
    std::cin >> str;
	const char* cStr = str.c_str();
//	str.c_str();
    std::cin.ignore(); // Clear newline character from input buffer
	while(str[i] != '\0')
	{
			if(std::isdigit(str[i]) != false)
					i++;
			else
			{
					std::cout << "just numbers from 1 to 8 allowed\n" << std::endl;
					return ;
			}
	}
	if (i > 1)
	{
		std::cout << "just numbers from 1 to 8 allowed\n" << std::endl;
		return ;
	}
	else 
	{
		index = std::atoi(cStr);
		index--;
		if(index >= 0 && index <= 7)
       		 _contacts[index].DisplayFull();
		 else
		 {
				 std::cout << "Invalid index. Just numbers from 1 to 8\n";
			 return ;
		 }

    }
}
