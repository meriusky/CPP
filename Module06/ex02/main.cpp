#include "Functions.hpp"
#include <iostream>
#include <cstdlib>// for srand
#include <ctime>// for time

int main()
{
    srand(time(0)); //starts the random number generator using the current time
	//Loops 5 times, so I can test the random generation multiple times
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();//creates a random object (A,B,C)
        std::cout << "Identify by pointer: ";
        identify(obj);//calls identify(Base * p) using the pointer object
//Whith this I can test pointer-based type identification using dynamic cast

        std::cout << "Identify by reference: ";		
		identify(*obj);//Calls identify(Base& p) using a reference to obj


        delete obj;//Free the dynamically allocated object to prevent memory leaks
        std::cout << "----" << std::endl;
    }

    return 0;
}

