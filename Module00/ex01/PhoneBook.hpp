#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip> // For formatting output
#include <cstdlib>

class PhoneBook {
private:
    int _index;          // Tracks the current index for adding contacts
	int _count;
    Contact _contacts[8]; // Fixed array of 8 Contact objects

public:
    PhoneBook(); // Default constructor
    ~PhoneBook(); // Destructor

    void AddContact(); // Add a new contact (takes input from the user)
    void SearchContacts() const; // Display all contacts and allow detailed view
//	int	 stringToInt(std::string);
};

#endif
