#include "Functions.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

Base* generate(void)
{
    std::srand(std::time(0)); // seed (do only once in main ideally)
    int r = std::rand() % 3;

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

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}

