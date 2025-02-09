#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->_brain->getIdea(index);
    return "";
}

