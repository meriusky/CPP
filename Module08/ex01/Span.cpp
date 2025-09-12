#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}
Span::~Span() {}
// Copy constructor
Span::Span(const Span& other) : _N(other._N), _data(other._data) {}

//Assignment operator: safely copy he contents of another span into this one.
Span& Span::operator=(const Span& other)
{//this: pointer to current object other: adress of the object we are copying from
    if (this != &other)//prevent self-assigment
	{
        _N = other._N;//copy the maz size
        _data = other._data;//copy the stored data(vector handles deep copy)
    }
    return *this;//allows chaining assignmets
}

//addNumber: enforce the rule that container can't hold more that _N elements
//_data.size(): current number of elements in the vector _N: maximum elemnts allowed
void Span::addNumber(int num)
{
    if (_data.size() >= _N)// in case of overflow
        throw std::overflow_error("Span is full");
    _data.push_back(num);//adds number to vector
}

// Shortest span: finds the smallest gap between any two numbers in the collection
int Span::shortestSpan() const
{
    if (_data.size() < 2)//needs 2 numbers, otherwise span is meaningless
        throw std::logic_error("Not enough elements to find span");

    std::vector<int> tmp = _data;//makes copy of _data 
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];//📍
	size_t i = 1;
	while (i < tmp.size() - 1)// loop through stored array, chaching diferences between neightbors
	{
    	int span = tmp[i + 1] - tmp[i];
    	if (span < minSpan)
        minSpan = span;
    	++i;
	}
    return minSpan;
}

// Longest span: find the largest distance between any two numbers is the collection
int Span::longestSpan() const
{
    if (_data.size() < 2)//needs min two numbers
        throw std::logic_error("Not enough elements to find span");
	//2📍
    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return maxVal - minVal;
}

// Print (optional)
void Span::print() const
{
    for (size_t i = 0; i < _data.size(); ++i)//loop through all elements of _data
        std::cout << _data[i] << " ";//prints each element separated by spaces
    std::cout << std::endl;
}
//📍 Why we need int minSpan = tmp[1] - tmp[0];
//tmp is a sorted copy of _data. The shortest span must be between two consecutive numbers in sorted order. So we need an initial reference to compare against: tmp[1] - tmp[0] is the first gap. Then, in the loop, we check all other consecutive gaps and update minSpan if we find a smaller one. Think of it like setting a “baseline” smallest span before scanning the rest.
//2📍 std::min_element finds the smallest value in _data
//	  std::max_element finds the largest value
