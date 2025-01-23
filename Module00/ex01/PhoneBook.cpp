#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _index(0), _count(0)
{
    // Initialize the PhoneBook
}

PhoneBook::~PhoneBook() 
{
	std::cout << "PhoneBook has been destroyed💥" << std::endl;
    // Cleanup if needed
}
/*
int PhoneBook::GetIndex() const 
{
    return _index;
}

Contact PhoneBook::GetContacts(int index) const
{
    if (index >= 0 && index < 8)
        return _contacts[index];
	std::cout << "Invalid index" << std::endl;
	return NULL;
}*/

void PhoneBook::AddContact(const Contact& contact) 
{
    _contacts[_index] = contact;
    _index = (_index + 1) % 8; // Wrap around if full
	if (_count < 8)
		_count++;
}

void PhoneBook::DisplayContacts() const 
{
    for (int i = 0; i < _count; ++i)
	{
        std::cout << "Contact " << i << ": " << _contacts[i].GetFirstName() << " "
                  << _contacts[i].GetLastName() << "\n";
    }
}
