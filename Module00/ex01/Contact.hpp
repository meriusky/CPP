#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream> // std::cout, std::cin
#include <string> //para hacer cosas con strings, la verdad ns

class Contact
{
// _ en el nom de la variable per mes endevant distinjir que es privada, es
// quelcom que fa la gent a c++
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string	_phoneNumber;
		std::string _darkestSecret;

	public:
		Contact();
//method constructor👷: debe llevar el mismo nombre que la clase y sirve para
//inicializar variables o cosas varias para preparar los objetos
		 Contact(const std::string& firstName, const std::string& lastName,
            const std::string& nickName, const std::string& phoneNumber,
            const std::string& darkestSecret);
//		Contact(std::string, std::string, std::string, std::string, std::string);
//method destructor👹: debe llevar el mismo nombre pero con ~ delante. Lo destruye
//y se utiliza para eliminar mallocs(de c++)
		~Contact();
		void SetContact(const std::string& firstName, const std::string& lastName,
                    const std::string& nickName, const std::string& phoneNumber,
                    const std::string& darkestSecret);
		void DisplayShort(int index) const; // Display in a table format (short view)
		void DisplayFull() const;/*
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;*/
};
//Como definir el contructor?
//Como definir los metodos?
//Replicarlo en el PhoneBook.hpp

#endif
