#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <algorithm>

// Canonical form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : numbersVector_(other.numbersVector_), numbersDeque_(other.numbersDeque_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        numbersVector_ = other.numbersVector_;
        numbersDeque_ = other.numbersDeque_;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Utility
bool PmergeMe::isNumber(const std::string &str) const {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

// Parse CLI input
void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isNumber(arg))
            throw std::runtime_error("Error: invalid input '" + arg + "'");

        int value = std::atoi(arg.c_str());
        if (value < 0)
            throw std::runtime_error("Error: only positive integers allowed");

        numbersVector_.push_back(value);
        numbersDeque_.push_back(value);
    }
}

// Printing wrappers
void PmergeMe::printBefore() const {
    printBeforeVector();
}

void PmergeMe::printAfter() const {
    printAfterVector();
}

// Private printing helpers
void PmergeMe::printBeforeVector() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printBeforeDeque() const {
    std::cout << "Before (deque): ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterVector() const {
    std::cout << "After: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const {
    std::cout << "After (deque): ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}

// Binary insert (for sorted containers)
void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) {
    size_t low = 0, high = sorted.size();
    while (low < high) {
        size_t mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    sorted.insert(sorted.begin() + low, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) {
    size_t low = 0, high = sorted.size();
    while (low < high) {
        size_t mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    sorted.insert(sorted.begin() + low, value);
}

// Sorting (dummy for now — replace with Ford-Johnson later)
void PmergeMe::mergeInsertSortVector(std::vector<int> &v) {
    std::sort(v.begin(), v.end());
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &d) {
    std::sort(d.begin(), d.end());
}

void PmergeMe::sortVector() {
    mergeInsertSortVector(numbersVector_);
}

void PmergeMe::sortDeque() {
    mergeInsertSortDeque(numbersDeque_);
}

// Timing wrappers
void PmergeMe::measureVectorSort() {
    clock_t start = clock();
    sortVector();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process " << numbersVector_.size()
              << " elements with std::vector: "
              << elapsed << " us" << std::endl;
}

void PmergeMe::measureDequeSort() {
    clock_t start = clock();
    sortDeque();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process " << numbersDeque_.size()
              << " elements with std::deque: "
              << elapsed << " us" << std::endl;
}

