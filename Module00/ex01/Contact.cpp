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

void Contact::DisplayShort(int index) const {
    if (_firstName.empty() && _lastName.empty()) {
        return; // Skip empty contacts
    }

    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|"
              << std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|"
              << std::setw(10) << (_nickName.length() > 10 ? _nickName.substr(0, 9) + "." : _nickName) << "\n";
}

void Contact::DisplayFull() const {
    std::cout << "First Name: " << _firstName << "\n"
              << "Last Name: " << _lastName << "\n"
              << "Nickname: " << _nickName << "\n"
              << "Phone Number: " << _phoneNumber << "\n"
              << "Darkest Secret: " << _darkestSecret << "\n";
}

/*#include <iostream>
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
}*/
