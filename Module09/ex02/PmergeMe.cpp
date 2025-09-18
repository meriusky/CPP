#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <stdexcept>

// -------------------- Constructors & Destructor --------------------
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
// -------------------- Public print functions --------------------
void PmergeMe::printBeforeVector() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorContainer.size(); ++i)
        std::cout << _vectorContainer[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterVector() const {
    std::cout << "After: ";
    for (size_t i = 0; i < _vectorContainer.size(); ++i)
        std::cout << _vectorContainer[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::binaryInsertVector(int value, size_t left, size_t right) {
    size_t low = left, high = right;
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (_vectorContainer[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    _vectorContainer.insert(_vectorContainer.begin() + low, value);
}

void PmergeMe::binaryInsertDeque(int value, size_t left, size_t right) {
    size_t low = left, high = right;
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (_dequeContainer[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    _dequeContainer.insert(_dequeContainer.begin() + low, value);
}
bool PmergeMe::isNumber(const std::string &s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

void PmergeMe::printBeforeDeque() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _dequeContainer.size(); ++i)
        std::cout << _dequeContainer[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const {
    std::cout << "After: ";
    for (size_t i = 0; i < _dequeContainer.size(); ++i)
        std::cout << _dequeContainer[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isNumber(arg)) {
            std::cerr << "Error: invalid input => " << arg << std::endl;
            throw std::runtime_error("Invalid input");
        }
        int value = atoi(arg.c_str());
        addToVector(value);
        addToDeque(value);
    }
}

// -------------------- Public sort functions --------------------
void PmergeMe::sortVector() {
    mergeInsertSortVector(_vectorContainer, 0, _vectorContainer.size() - 1);
}

void PmergeMe::sortDeque() {
    mergeInsertSortDeque(_dequeContainer, 0, _dequeContainer.size() - 1);
}

// -------------------- Private merge-insert sort for vector --------------------
void PmergeMe::mergeInsertSortVector(std::vector<int> &vec, size_t left, size_t right) {
    if (left >= right) return;

    // Split
    size_t mid = left + (right - left) / 2;
    mergeInsertSortVector(vec, left, mid);
    mergeInsertSortVector(vec, mid + 1, right);

    // Merge using insertion
    std::vector<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (vec[i] < vec[j])
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }
    while (i <= mid) temp[k++] = vec[i++];
    while (j <= right) temp[k++] = vec[j++];

    for (size_t t = 0; t < temp.size(); ++t)
        vec[left + t] = temp[t];
}

// -------------------- Private merge-insert sort for deque --------------------
void PmergeMe::mergeInsertSortDeque(std::deque<int> &dq, size_t left, size_t right) {
    if (left >= right) return;

    size_t mid = left + (right - left) / 2;
    mergeInsertSortDeque(dq, left, mid);
    mergeInsertSortDeque(dq, mid + 1, right);

    std::deque<int> temp;
    size_t i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (dq[i] < dq[j])
            temp.push_back(dq[i++]);
        else
            temp.push_back(dq[j++]);
    }
    while (i <= mid) temp.push_back(dq[i++]);
    while (j <= right) temp.push_back(dq[j++]);

    for (size_t t = 0; t < temp.size(); ++t)
        dq[left + t] = temp[t];
}

// -------------------- Timing functions --------------------
double PmergeMe::measureVectorSort() {
    clock_t start = std::clock();
    sortVector();
    clock_t end = std::clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

double PmergeMe::measureDequeSort() {
    clock_t start = std::clock();
    sortDeque();
    clock_t end = std::clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// -------------------- Functions to populate containers --------------------
void PmergeMe::addToVector(int n) {
    _vectorContainer.push_back(n);
}

void PmergeMe::addToDeque(int n) {
    _dequeContainer.push_back(n);
}

