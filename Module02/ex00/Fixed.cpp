#include "Fixed.hpp"


Fixed::Fixed() : _number(0) // Default Constructor: Initializes _value to 0
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)// Copy Constructor: Copies the value from another Fixed instance
{//*1 this
    std::cout << "Copy constructor called\n";
    *this = other;  // Uses the assignment operator
}

Fixed &Fixed::operator=(const Fixed &other)// Copy Assignment Operator: Handles deep copy
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)// Check for self-assignment
        this->_number = other.getRawBits();
    return *this;
}

Fixed::~Fixed() // Destructor
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const // Getter: Returns the raw integer value
{
    std::cout << "getRawBits member function called\n";
    return this->_number;
}

void Fixed::setRawBits(int const raw) // Setter: Sets the raw integer value
{
    std::cout << "setRawBits member function called\n";
    this->_number = raw;
}
//*1 Why am I usig this?
//With this we are takeing
