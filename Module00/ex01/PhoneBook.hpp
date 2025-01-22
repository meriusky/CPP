#include <iostream>
#include <string>

class PhoneBook
{
	private:
		int		_index;
		Contact _contacts[8];
	
	public:
		PhoneBook(int &, Contact);
		~PhoneBook();
		int		GetIndex();
		Contact	GetContacts();
}
