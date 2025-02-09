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
/*How is the operator working?*/
