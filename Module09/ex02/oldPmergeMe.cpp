#include "PmergeMe.hpp"
#include <cstdlib>   // for atoi
#include <cctype>    // for isdigit

PmergeMe::PmergeMe() {}
// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other): vec(other.vec), deq(other.deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

//Parse CLI arguments
void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i) // skip argv[0] (program name)
    {
        std::string token(argv[i]);

        //Check if it's a valid number
        if (!isNumber(token)) 
		{
            throw std::runtime_error("Error: invalid number => " + token);
        }

        //Convert string → int
        long num = std::atol(token.c_str());
        if (num <= 0) 
		{
            throw std::runtime_error("Error: only positive integers allowed");
        }

        if (num > INT_MAX) 
		{
            throw std::runtime_error("Error: number too large");
        }
        // 3. Push into both containers
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
}
// ------------ Print before sorting ------------
void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// ------------ Print after sorting ------------
void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) 
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// Sort vector using your merge-insert algorithm
void PmergeMe::sortVector() 
{
    // call your merge-insert sort on vec
    mergeInsertSort(vec, 0, vec.size() - 1);
}

// Sort deque using the same algorithm
void PmergeMe::sortDeque() 
{
    // call your merge-insert sort on deq
    mergeInsertSort(deq, 0, deq.size() - 1);
}
// ------------ Check if string is number ------------
bool PmergeMe::isNumber(const std::string &s) const
{
	size_t i = 0;
    while (i < s.size()) 
	{
        if (!std::isdigit(s[i]))
            return false;
		i++;
    }
    return !s.empty();
}
//This file is doing:
//1.Reading the command line arguments
//2.Validating each one (must be positive integer, no invalid chars)
//3.Convert strings -> integers
//4.Store them both containers

