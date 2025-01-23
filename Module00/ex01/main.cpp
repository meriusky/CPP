#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>


int main()
{
    PhoneBook phoneBook;

    // Add a few contacts
    Contact c1(std::string("Paula"), std::string("Fuentes"), std::string("Szasi"),
				std::string("123456789"), std::string("Her boyfriend is from porahi"));
    Contact c2(std::string("Andrei"), std::string("Cojocaru"), std::string("Badalot4"),
				std::string("987654321"), std::string("His DNA is Romanian"));

    phoneBook.AddContact(c1);
    phoneBook.AddContact(c2);
 // Use getters to access private members
//    std::cout << "First Name: " << contact.GetFirstName() << "\n";
  //  std::cout << "Last Name: " << contact.GetLastName() << "\n";
//    std::cout << "Nickname: " << contact.GetNickName() << "\n";
  //  std::cout << "Phone Number: " << contact.GetPhoneNumber() << "\n";
//    std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << "\n";
    // Display all contacts
    phoneBook.DisplayContacts();

    return 0;
}
