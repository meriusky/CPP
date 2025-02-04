#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // For roundf()

class Fixed 
{
	private:
	    int _value;                           // Stores the fixed-point number
	    static const int _fractionalBits = 8; // Number of fractional bits (always 8)
	
	public:
	    // Orthodox Canonical Form
	    Fixed();                          //Default constructor
	    Fixed(const Fixed &other);         //Copy constructor
	    Fixed &operator=(const Fixed &other); //Copy assignment operator
	    ~Fixed();                         //Destructor
	    Fixed(const int intValue);         //Constructor from int
	    Fixed(const float floatValue);     //Constructor from float
	    int getRawBits(void) const;        //Getter for raw value
	    void setRawBits(int const raw);    //Setter for raw value
	    float toFloat(void) const;         //Converts to float
	    int toInt(void) const;             //Converts to int
};
   	// Overloaded << operator for printing
    std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif
