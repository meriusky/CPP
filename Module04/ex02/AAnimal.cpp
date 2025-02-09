#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other) 
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

// No implementation for makeSound() because it's pure virtual

std::string AAnimal::getType() const
{
    return this->type;
}

