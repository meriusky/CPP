#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed() : _value(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed &other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Uses the copy assignment operator
}

//Copy Assignment Operator
Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

//Constructor from int
Fixed::Fixed(const int intValue) 
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits; // Shift left by 8 bits (multiply by 256)
}

//Constructor from float
Fixed::Fixed(const float floatValue) 
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _fractionalBits)); // Multiply & round
}

//Get raw value
int Fixed::getRawBits(void) const 
{
    return _value;
}

//Set raw value
void Fixed::setRawBits(int const raw) 
{
    _value = raw;
}

//Convert fixed-point to float
float Fixed::toFloat(void) const 
{
    return (float)_value / (1 << _fractionalBits);
}

//Convert fixed-point to int
int Fixed::toInt(void) const 
{
    return _value >> _fractionalBits; // Shift right by 8 bits (divide by 256)
}

//Overload << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}
