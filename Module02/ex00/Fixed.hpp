#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int                 _number;  //Stores the fixed-point value
    static const int    _frctBitsNum = 8;  //Number of fractional bits (always 8)

public:

    Fixed(); // Default Constructor that initializes the fixed-point number value to 0.
    Fixed(const Fixed &other); //Copy constructor
    Fixed &operator=(const Fixed &other); //copy assignment operator overload.
    ~Fixed(); //Destructor
    int getRawBits(void) const; //Getter for the raw fixed-point value
    void setRawBits(int const raw); //Setter for the raw fixed-point value
};

#endif