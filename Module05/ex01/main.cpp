#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try
    {
        Bureaucrat andrei("Andrei", 50);        
        Bureaucrat paula("Paula", 140);

        Form passport("Passport", 100, 50);

        std::cout << passport << std::endl;

        andrei.signForm(passport);
        std::cout << passport << std::endl;

        paula.signForm(passport);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
