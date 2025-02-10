#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;//*1
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other)//*1
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
/*How is the operator working?

 When is operator= used?
 The copy assignment operator is called when an existing object is assigned 
 another object.
Exemple:     Animal a1;
             Animal a2;
             a2 = a1; // Calls operator=

This is a copy assignment operator. It allows one Animal object to be 
assigned to another using =    👇
	➡️	Animal& Animal::operator=(const Animal& other) ⬅️

		➡️  if (this != &other) ⬅️
this: is a pointer to the current object
&other: is the adress of the object being assigned
this = &other:  the object is being assigned to itself, so we skip the assignment 
                to avoid unnecessary work.

      ➡️  this->type = other.type;  ⬅️
Copies the value of other.type into this->type.
	
 *
*/
