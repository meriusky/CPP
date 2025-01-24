#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip> // For formatting output

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
};

#endif

/*#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		_index;
		int		_count;
		Contact _contacts[8];
	
	public:
//no te res perque el phonebook sera 8 sera 3 o sera al inici 0 perque no
//te cap encara, per aixo esta vuit.
		PhoneBook();
		~PhoneBook();
//const per garantitzar que no es modificara l'objecte
//		int		GetIndex() const;
//		Contact	GetContacts(int index) const;
		void AddContact(const Contact& contact); // Add a new contact
		void SearchContact() const; //mostrara los contactos
//		void DisplayContacts() const; // Display all contacts
};

#endif*/
