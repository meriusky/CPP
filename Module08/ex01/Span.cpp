#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _N(N) {}

// Destructor
Span::~Span() {}

// Copy constructor
Span::Span(const Span& other) : _N(other._N), _data(other._data) {}

// Assignment operator
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        _data = other._data;
    }
    return *this;
}

// Add a single number
void Span::addNumber(int num)
{
    if (_data.size() >= _N)
        throw std::overflow_error("Span is full");
    _data.push_back(num);
}

// Shortest span
int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements to find span");

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; ++i)
    {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// Longest span
int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements to find span");

    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return maxVal - minVal;
}

// Print (optional)
void Span::print() const
{
    for (size_t i = 0; i < _data.size(); ++i)
        std::cout << _data[i] << " ";
    std::cout << std::endl;
}

