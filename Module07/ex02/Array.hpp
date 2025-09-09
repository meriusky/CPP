#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // for std::out_of_range

template <typename T>
class Array
{
	private:
	    T* _data;//pointer to a dynamically allocated array (will hold elements)
	    unsigned int _size;//keeps track of how many elements the array contains

	public:
		Array() : _data(NULL), _size(0) {}
    //Constructor with size
		Array(unsigned int n) : _data(new T[n]()), _size(n) {}
	//Copy constructor
   		Array(const Array& other) : _data(NULL), _size(0)
	    {
	        *this = other;
	    }
//Assignment operator: Prevents memory leaks, allocates new array of the same size as "other", copies each element one by one (deep copy, not just the poiter) Return *this to allow chaining (a = b = c)
	    Array& operator=(const Array& other)
	    {
	        if (this != &other)//avoid self assignment
	        {
	            delete[] _data;// free old data
	            _size = other._size;
	            if (_size > 0)
	            {
	                _data = new T[_size];//allocate new memory
	                for (unsigned int i = 0; i < _size; ++i)
	                    _data[i] = other._data[i];//deep copy
	            }
	            else
	                _data = NULL;
	        }
	        return *this;
	    }

	   ~Array()
	   {
	        delete[] _data;
	   }

// Subscript operator (with bounds checking): Provides array like acces with[]
	    T& operator[](unsigned int index)
	    {
	        if (index >= _size)
	            throw std::out_of_range("Index out of bounds");// it throws out_of_range if you try to access invalid indices
	        return _data[index];
	    }

	    const T& operator[](unsigned int index) const
	    {
	        if (index >= _size)
	            throw std::out_of_range("Index out of bounds");
	        return _data[index];
	    }

    // Size function: return how many elements are in the array, Marked const so you can call it on const arrays.
	    unsigned int size() const
	    {
	        return _size;
	    }
};
#endif
//Constructor whith size: Crates an array of size n. new T[n] allocates memory for n elements of type T and value initializes them (0 for num and empty string for std::string)
//This class:
//Wraps a dynamic array,
//Manages memory safely,
//Provides deep copies,
//Provides bounds-checked [] access,
//Is generic thanks to templates.
//So it’s essentially a mini safer std::vector.
//


/* EN CAS D'UTILITZAR .TPP
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // for std::out_of_range

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    // Constructors
    Array();
    Array(unsigned int n);
    Array(const Array& other);

    // Assignment
    Array& operator=(const Array& other);

    // Destructor
    ~Array();

    // Subscript operator
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // Size
    unsigned int size() const;
};

// 👇 This is where we include the implementation
#include "Array.tpp"

#endif
*/
