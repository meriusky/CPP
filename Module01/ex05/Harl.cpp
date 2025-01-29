#include "Harl.hpp"

Harl::Harl()
{//Each _ptr[] corresponds directly to a _levels[] value.
    _ptr[0] = &Harl::debug;
    _ptr[1] = &Harl::info;
    _ptr[2] = &Harl::warning;
    _ptr[3] = &Harl::error;

    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";

}
Harl::~Harl() {}
//Each function prints tehir complain message with a heather(debug, info, warning, error)
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)//We initialice the i = 0, while i < 4 do i++
    {
        if (_levels[i].compare(level) == 0)//If the input matches de level
        {
            (this->*_ptr[i])();//accses to the function pointer //*ex
            return;
        }
    }
	//If no match is found, print an error message
    std::cout << level << " level like that doesn't exist you m...........!" << std::endl;
}
/*ex:	What Happens if level = "INFO"?

   1. The loop finds that _levels[1] == "INFO".
   2.  _ptr[1] holds &Harl::info, which is the memory address of info().
   3.  (this->*_ptr[1])(); calls the info() function.*/
