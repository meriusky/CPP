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
	    Fixed();                          // Default constructor
	    Fixed(const Fixed &other);         // Copy constructor
	    Fixed &operator=(const Fixed &other); // Copy assignment operator
	    ~Fixed();                         // Destructor

	    // New Constructors
	    Fixed(const int intValue);         // Constructor from int
	    Fixed(const float floatValue);     // Constructor from float

	    // Member functions
	    int getRawBits(void) const;        // Getter for raw value
	    void setRawBits(int const raw);    // Setter for raw value
	    float toFloat(void) const;         // Converts to float
	    int toInt(void) const;             // Converts to int

	    // Comparison Operators
	    bool operator>(const Fixed &other) const;
	    bool operator<(const Fixed &other) const;
	    bool operator>=(const Fixed &other) const;
 	   bool operator<=(const Fixed &other) const;
	    bool operator==(const Fixed &other) const;
	    bool operator!=(const Fixed &other) const;

	    // Arithmetic Operators
	    Fixed operator+(const Fixed &other) const;
	    Fixed operator-(const Fixed &other) const;
	    Fixed operator*(const Fixed &other) const;
	    Fixed operator/(const Fixed &other) const;

	    // Increment / Decrement Operators
	    Fixed &operator++();    // Pre-increment (++a)
	    Fixed operator++(int);  // Post-increment (a++)
	    Fixed &operator--();    // Pre-decrement (--a)
	    Fixed operator--(int);  // Post-decrement (a--)

	    // Min & Max Functions
	    static Fixed &min(Fixed &a, Fixed &b);
    	static const Fixed &min(const Fixed &a, const Fixed &b);
	    static Fixed &max(Fixed &a, Fixed &b);
    	static const Fixed &max(const Fixed &a, const Fixed &b);

	    // Overloaded << operator for printing
 	   friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};
#endif

