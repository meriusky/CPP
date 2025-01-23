#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Default constructor contact creator" << std::endl;
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

// Constructor definition: no retorna solo construye, lo hace solo
Contact::Contact(std::string firstName, std::string lastName, 
                 std::string nickName, std::string phoneNumber, 
                 std::string darkestSecret): _firstName(firstName), 
				_lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber),
			   	_darkestSecret(darkestSecret)
{
//	_firstName = firstName; es lo mismo pero mejor👆
    std::cout << "Contact created: " << _firstName << " " << _lastName << std::endl;
}

// Destructor definition: no retorna solo destruye, lo hace solo
Contact::~Contact()
{
    std::cout << "Contact destroyed: " << _firstName << " " << _lastName << std::endl;
}

// Getter method definitions
std::string Contact::GetFirstName() const
{
    return _firstName;
}

std::string Contact::GetLastName() const
{
    return _lastName;
}

std::string Contact::GetNickName() const
{
    return _nickName;
}

std::string Contact::GetPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::GetDarkestSecret() const
{
    return _darkestSecret;
}
