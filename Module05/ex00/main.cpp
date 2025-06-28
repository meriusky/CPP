#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        Bureaucrat jim("Jim", 1);
        std::cout << jim << std::endl;
        jim.incrementGrade(); // should throw
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat tim("Tim", 151); // should throw
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
