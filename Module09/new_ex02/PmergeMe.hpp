#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe 
{
    public:
        PmergeMe();
        ~PmergeMe();

        // Sort functions for different containers
        void sortVector(std::vector<int>& data);
        void sortDeque(std::deque<int>& data);

        // Utility
        static void printSequence(const std::vector<int>& data);
        static void printSequence(const std::deque<int>& data);
        static bool isPositiveInteger(const char* str);
};

#endif

