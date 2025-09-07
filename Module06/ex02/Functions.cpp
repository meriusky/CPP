#include "Functions.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

Base* generate(void)
{
    std::srand(std::time(0)); //seeds the random number generator using the current time
    int r = std::rand() % 3;
	//generates a random number between 0 and 2, this decides which class(A,B,C)
    if (r == 0)
    {
        std::cout << "Generated A" << std::endl;
        return new A();
    }
    else if (r == 1)
    {
        std::cout << "Generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}
//Takes a pointer to Base
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))//tries to safely cast p to a pointer of type A, if not returns NULL
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
//Prints teh real type: Goal, figure out whether p actually refers to an object type A, B or C
void identify(Base& p)
{
    Base* ptr = &p; // take the address
    if (dynamic_cast<A*>(ptr))//tries to cast ptr to *A, if yes Prints A
        std::cout << "A\n";
    else if (dynamic_cast<B*>(ptr))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(ptr))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

