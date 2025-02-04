#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int                 _number;  //Stores the fixed-point value
    static const int    _frctBitsNum = 8;  //Number of fractional bits (always 8)

public:

    Fixed(); //1. Default Constructor that initializes the fixed-point number value to 0.
    Fixed(const Fixed &other); //2.Copy constructor
    Fixed &operator=(const Fixed &other); //3. Copy assignment operator overload.
    ~Fixed(); //4. Destructor
    int getRawBits(void) const; //Getter for the raw fixed-point value
    void setRawBits(int const raw); //Setter for the raw fixed-point value
};

#endif

//Orthodox Canonical Form: 
//Is a set of four mandatory member functions that ensure a class behaves properly 
//in terms of object creation, destruction, and assignment.
//A class in OCF includes:
// 1. Default Constructor → ClassName();
// 2. Copy Constructor → ClassName(const ClassName &other);
// 3. Copy Assignment Operator → ClassName &operator=(const ClassName &other);
// 4. Destructor → ~ClassName();
//
//OFC is usefull because:
//1. Prevents memory leaks (perfect for handeling dynamic memory)
//2. Ensures deep copies instead of shallow copies
//3. Handles self-assignment safely
