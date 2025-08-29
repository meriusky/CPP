#include "Functions.hpp"
#include <iostream>

int main()
{
    std::srand(std::time(0)); // seed once in main

    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        std::cout << "Identify by pointer: ";
        identify(obj);

        std::cout << "Identify by reference: ";
        identify(*obj);

        delete obj;
        std::cout << "----" << std::endl;
    }

    return 0;
}

