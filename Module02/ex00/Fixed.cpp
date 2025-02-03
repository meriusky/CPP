#include "Fixed.hpp"

// Default Constructor: Initializes _value to 0
Fixed::Fixed() : _number(0) 
{
    std::cout << "Default constructor called\n";
}

// Copy Constructor: Copies the value from another Fixed instance
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;  // Uses the assignment operator
}

// Copy Assignment Operator: Handles deep copy
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)// Check for self-assignment
        this->_number = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called\n";
}

// Getter: Returns the raw integer value
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called\n";
    return this->_number;
}

// Setter: Sets the raw integer value
void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called\n";
    this->_number = raw;
}
