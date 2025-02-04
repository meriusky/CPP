#include "Fixed.hpp"
//we give the value before the object exist
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
    if (this != &other)// If pointer "this" is not the same as pinter "other".
        this->_number = other.getRawBits();
	//we change the value of number to the value that we will get from getRawBits
    return *this;//we return because the operator demandeit
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
//*1 Why am I usig this?(explained with the actual main)
//"this" is b, other is a. When we write "*this = other" we are calling the
//operatior. Yes it is what it is. It might sound crazy but thats what is happening.
//In other cases that we are not usig this main to give the exemple "this" will be
//the object thats is being build and called.

