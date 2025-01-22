#include <iostream>
#include <string>
#include "Contact.hpp"

// Constructor definition: no retorna solo construye, lo hace solo
Contact::Contact(std::string &firstName, std::string &lastName, 
                 std::string &nickName, std::string &phoneNumber, 
                 std::string &darkestSecret): _firstName(firstName), 
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
std::string Contact::GetFirstName() 
{
    return _firstName;
}

std::string Contact::GetLastName() 
{
    return _lastName;
}

std::string Contact::GetNickName()
{
    return _nickName;
}

std::string Contact::GetPhoneNumber()
{
    return _phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
    return _darkestSecret;
}

int main()
{
    std::string firstName = "Paula";
    std::string lastName = "Fuentes";
    std::string nickName = "Sasi";
    std::string phoneNumber = "123456789";
    std::string darkestSecret = "Her boyfriend is from porahi";

    // Create a Contact object
    Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

    // Use getters to access private members
    std::cout << "First Name: " << contact.GetFirstName() << "\n";
    std::cout << "Last Name: " << contact.GetLastName() << "\n";
    std::cout << "Nickname: " << contact.GetNickName() << "\n";
    std::cout << "Phone Number: " << contact.GetPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << "\n";

    return 0;
}

