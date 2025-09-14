#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
    	unsigned int _N;//max size of a container
    	std::vector<int> _data;//store the integer

	public:
    	Span(unsigned int N);
    	~Span();
    //Copy constructor
    	Span(const Span& other);

    //Assignment operator: return a reference to the current object
    	Span& operator=(const Span& other);

    //Add a single number
    	void addNumber(int num);

//Add a range: lets me add multiple numbers at once instead of calling addNumber in loop
    	template <typename InputIterator>
    	void addRange(InputIterator begin, InputIterator end)
    	{
			//Make sure thet adding this many elements won't exceed the maximom capacity _N
        	if (_data.size() + std::distance(begin, end) > _N)
            	throw std::overflow_error("Not enough space in Span");
        	_data.insert(_data.end(), begin, end);//inserts the elements
    	}

    	int shortestSpan() const; //Find shortest span
    	int longestSpan() const; //Find longest span
    	void print() const;//For debugging
};

#endif
//std::distance: Calculates how many elements are in the range (like end - begin for vector but works for all iterator types)
