#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->_brain->getIdea(index);
    return "";
}
