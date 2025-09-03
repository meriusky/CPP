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
    // Default constructor: empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _data(NULL), _size(0)
    {
        *this = other;
    }

    // Assignment operator
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            if (_size > 0)
            {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
            else
                _data = NULL;
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // Subscript operator (with bounds checking)
    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    // Size function
    unsigned int size() const
    {
        return _size;
    }
};

#endif
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
