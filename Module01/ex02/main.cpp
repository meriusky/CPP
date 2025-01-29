#include <iostream>
int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;//*1
    std::string& stringREF = str; //*2

    std::cout << "Memory address str: " << &str << std::endl;
    std::cout << "Memory address stringPTR : " << stringPTR << std::endl;
    std::cout << "Memory address stringREF : " << &stringREF << std::endl;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value of stringREF : " << stringREF << std::endl;
    return(0);
}
//1: The pointer is saving the memory address in the variable stringPTR
//2: The reference is like putting another name to the variable, it can't be NULL and
// : and you can modify it
