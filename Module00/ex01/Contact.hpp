#include <iostream> // std::cout, std::cin
#include <string> //para hacer cosas con strings, la verdad ns

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string	_phoneNumber;
		std::string _darkestSecret;

	public:
//method constructor👷: debe llevar el mismo nombre que la clase y sirve para
//inicializar variables o cosas varias para preparar los objetos
		Contact(std::string &, std::string &, std::string &, std::string &, std::string &);
//method destructor👹: debe llevar el mismo nombre pero con ~ delante. Lo destruye
//y se utiliza para eliminar mallocs(de c++)
		~Contact();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetPhoneNumber();
		std::string GetDarkestSecret();
}
//Como definir el contructor?
//Como definir los metodos?
//Replicarlo en el PhoneBook.hpp

