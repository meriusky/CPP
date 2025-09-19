#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// Helper: Merge-insert (Ford-Johnson) implementation for vector
static void fordJohnsonVector(std::vector<int>& v) 
{
    if (v.size() <= 1)
        return;

    std::vector<int> left, right;
    for (size_t i = 0; i + 1 < v.size(); i += 2) 
    {
        if (v[i] < v[i + 1]) 
        {
            left.push_back(v[i]);
            right.push_back(v[i + 1]);
        } else 
        {
            left.push_back(v[i + 1]);
            right.push_back(v[i]);
        }
    }
    if (v.size() % 2 != 0)
        left.push_back(v.back());

    fordJohnsonVector(left);
    fordJohnsonVector(right);

    v.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(v));
}

// Helper: Ford-Johnson for deque
static void fordJohnsonDeque(std::deque<int>& dq) {
    if (dq.size() <= 1)
        return;

    std::deque<int> left, right;
    for (size_t i = 0; i + 1 < dq.size(); i += 2) {
        if (dq[i] < dq[i + 1]) {
            left.push_back(dq[i]);
            right.push_back(dq[i + 1]);
        } else {
            left.push_back(dq[i + 1]);
            right.push_back(dq[i]);
        }
    }
    if (dq.size() % 2 != 0)
        left.push_back(dq.back());

    fordJohnsonDeque(left);
    fordJohnsonDeque(right);

    dq.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(dq));
}

// Interface functions
void PmergeMe::sortVector(std::vector<int>& data) {
    fordJohnsonVector(data);
}

void PmergeMe::sortDeque(std::deque<int>& data) {
    fordJohnsonDeque(data);
}

// Utility print
void PmergeMe::printSequence(const std::vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << (i + 1 < data.size() ? " " : "");
    std::cout << std::endl;
}

void PmergeMe::printSequence(const std::deque<int>& data) {
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << (i + 1 < data.size() ? " " : "");
    std::cout << std::endl;
}

// Check if string is positive integer
bool PmergeMe::isPositiveInteger(const char* str) {
    if (!str || *str == '\0')
        return false;
    for (size_t i = 0; str[i]; ++i) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return std::atoi(str) > 0;
}

