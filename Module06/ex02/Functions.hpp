#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp" //I include the Base class and the derived Classes A,B,C

//At runtime, this function randomly create an instance of A, B or C and return it as a Base*
Base* generate(void);// function generate, returns a pointer to a Base object
void identify(Base* p);//function takes the pointer to Base and prints the actual type of the objectit points (A,B,C)
void identify(Base& p);// Function that prints the real type using a reference.

#endif

