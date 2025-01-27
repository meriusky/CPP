/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:57:59 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/27 17:05:26 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName,
                 const std::string& nickName, const std::string& phoneNumber,
                 const std::string& darkestSecret)
    : _firstName(firstName), _lastName(lastName), _nickName(nickName),
      _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

Contact::~Contact() {}

void Contact::SetContact(const std::string& firstName, const std::string& lastName,
                         const std::string& nickName, const std::string& phoneNumber,
                         const std::string& darkestSecret) {
    _firstName = firstName;
    _lastName = lastName;
    _nickName = nickName;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

void Contact::DisplayShort(int index) const
{
	index++;
    if (_firstName.empty() && _lastName.empty())
        return; // Skip empty contacts
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|"
              << std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|"
              << std::setw(10) << (_nickName.length() > 10 ? _nickName.substr(0, 9) + "." : _nickName) << "\n";
}

void Contact::DisplayFull() const
{
    std::cout << "First Name: " << _firstName << "\n"
              << "Last Name: " << _lastName << "\n"
              << "Nickname: " << _nickName << "\n"
              << "Phone Number: " << _phoneNumber << "\n"
              << "Darkest Secret: " << _darkestSecret << "\n";
}
