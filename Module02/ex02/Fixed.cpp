#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed() : _value(0) {}

//Copy Constructor
Fixed::Fixed(const Fixed &other)
{
    *this = other; // Uses the copy assignment operator
}

//Copy Assignment Operator
Fixed &Fixed::operator=(const Fixed &other) 
{
    if (this != &other) 
        this->_value = other.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed() {}

//Constructor from int
Fixed::Fixed(const int intValue) 
{
    _value = intValue << _fractionalBits; // Shift left by 8 bits (multiply by 256)
}

//Constructor from float
Fixed::Fixed(const float floatValue) 
{
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

//Comparison Operators
bool Fixed::operator>(const Fixed &other) const 
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const 
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return this->_value != other._value;
}

//Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}

//Increment & Decrement Operators
Fixed &Fixed::operator++() 
{ // Pre-increment
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) 
{ // Post-increment
    Fixed temp = *this;
    _value++;
    return temp;
}

Fixed &Fixed::operator--() 
{ // Pre-decrement
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) 
{ // Post-decrement
    Fixed temp = *this;
    _value--;
    return temp;
}

//Min & Max Functions
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;//*1
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;//*1
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;//*1
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;//*1
}
/* The same as writing these
{
    if (a < b)
        return a;
    else
        return b;
}*/

