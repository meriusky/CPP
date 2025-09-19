#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <algorithm>//provides algorithms like std::sort
#include <iomanip>  // for std::fixed and std::setprecision

// Canonical form
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other): numbersVector_(other.numbersVector_), numbersDeque_(other.numbersDeque_) {}
PmergeMe& PmergeMe::operator=(const PmergeMe &other) 
{
    if (this != &other) {
        numbersVector_ = other.numbersVector_;
        numbersDeque_ = other.numbersDeque_;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// Utility
bool PmergeMe::isNumber(const std::string &str) const 
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i) //loop through each character
    {
        if (!std::isdigit(str[i]))//check if char is between 0 and 9
            return false;
    }
    return true;
}

// Parse CLI input
void PmergeMe::parseInput(int argc, char **argv) 
{
    for (int i = 1; i < argc; ++i) //loop through the command line arguments
    {
        //for easier handling
        std::string arg = argv[i];//convert the "raw c-string(char *)" into std::string 
        if (!isNumber(arg))
            throw std::runtime_error("Error: invalid input '" + arg + "'");
        //converts string into integer
        int value = std::atoi(arg.c_str());
        if (value < 0)//reject negative numbers
            throw std::runtime_error("Error: only positive integers allowed");
        //We push inside the containers
        numbersVector_.push_back(value);
        numbersDeque_.push_back(value);
    }
}

// Printing wrappers
void PmergeMe::printBefore() const 
{
    printBeforeVector();
}
void PmergeMe::printAfter() const 
{
    printAfterVector();
}

// Private printing helpers
void PmergeMe::printBeforeVector() const 
{
    std::cout << "Before: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printBeforeDeque() const 
{
    std::cout << "Before (deque): ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterVector() const 
{
    std::cout << "After: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const 
{
    std::cout << "After (deque): ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}

// Binary insert(for sorted containers): &sorted is already sorted, value is the new number
void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) 
{
    size_t low = 0, high = sorted.size();//low= beginning of the vector hight= one past the end of the vector 
    while (low < high) 
    {
        size_t mid = (low + high) / 2;//find the middle element value
        if (sorted[mid] < value)//if yes, the new element must go after mid
            low = mid + 1;
        else
            high = mid;
    }
//take the calculated position low and inserts the new valure right there.
//the std::vector shifts all elements after low.
    sorted.insert(sorted.begin() + low, value);
}
void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) 
{
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
// Ford-Johnson (Merge-Insert) for vector
void PmergeMe::mergeInsertSortVector(std::vector<int> &v) 
{
    if (v.size() <= 1) return; // already sorted

    std::vector<int> sorted;//empty stored container
    sorted.push_back(v[0]); //push the first element

    // Insert remaining elements using binaryInsertVector
    for (size_t i = 1; i < v.size(); ++i)
    {
        binaryInsertVector(sorted, v[i]);
    }

    v = sorted; // copy back sorted elements
}

// Ford-Johnson (Merge-Insert) for deque
void PmergeMe::mergeInsertSortDeque(std::deque<int> &d) 
{
    if (d.size() <= 1) return;

    std::deque<int> sorted;
    sorted.push_back(d[0]);

    for (size_t i = 1; i < d.size(); ++i)
    {
        binaryInsertDeque(sorted, d[i]);
    }

    d = sorted;
}
void PmergeMe::sortVector() 
{
    mergeInsertSortVector(numbersVector_);
}

void PmergeMe::sortDeque() 
{
    mergeInsertSortDeque(numbersDeque_);
}

// Timing wrappers
void PmergeMe::measureVectorSort() 
{
    clock_t start = clock();//returns the current processor time
    sortVector();//calls the sorting function
    clock_t end = clock();//records the end time
    //end-start gives the number of clock ticks 
    //CLOCKS_PERSEC is a constant representing how many clock ticks are in one second
    //multiplying by 1e6 converts it to microseconds
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process " << numbersVector_.size()
              << " elements with std::vector: "
              << std::fixed << std::setprecision(3)  // <-- controls decimals
              << elapsed << " us" << std::endl;
}

void PmergeMe::measureDequeSort() 
{
    clock_t start = clock();
    sortDeque();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process " << numbersDeque_.size()
              << " elements with std::deque: "
              << std::fixed << std::setprecision(3)  // <-- controls decimals
              << elapsed << " us" << std::endl;
}

