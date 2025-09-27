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
    if (this != &other) 
    {
        numbersVector_ = other.numbersVector_;
        numbersDeque_ = other.numbersDeque_;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

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

//Parse CLI input
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

//🖨️Printing🖨️
void PmergeMe::printBefore() const 
{
    printBeforeVector();
    printBeforeDeque();
}
void PmergeMe::printAfter() const 
{
    printAfterVector();
    printAfterDeque();
}

//🖨️Private printing helpers🖨️
void PmergeMe::printBeforeVector() const 
{
    std::cout << "Before Vector: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::printBeforeDeque() const 
{
    std::cout << "Before Deque: ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::printAfterVector() const 
{
    std::cout << "After Vector: ";
    for (size_t i = 0; i < numbersVector_.size(); ++i)
        std::cout << numbersVector_[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::printAfterDeque() const 
{
    std::cout << "After Deque: ";
    for (size_t i = 0; i < numbersDeque_.size(); ++i)
        std::cout << numbersDeque_[i] << " ";
    std::cout << std::endl;
}

// Binary insertion helper
void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) 
{
    size_t low = 0;//begining
    size_t high = sorted.size();//end
    while (low < high) //while it doesen't reach the end
    {
        size_t mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    sorted.insert(sorted.begin() + low, value);
}
void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) 
{
    size_t low = 0;
    size_t high = sorted.size();
    while (low < high) 
    {
        size_t mid = (low + high) / 2;
        if (sorted[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    sorted.insert(sorted.begin() + low, value);
}

// Ford-Johnson / Merge-Insert sort
void PmergeMe::fordJohnsonSortVector(std::vector<int> &arr) 
{
    if (arr.size() <= 1) return;

    std::vector<int> sorted;
    
    //Create pairs and push the smaller of each pair to sorted
    for (size_t i = 0; i + 1 < arr.size(); i += 2) 
    {
        if (arr[i] < arr[i + 1])
            sorted.push_back(arr[i]);
        else
            sorted.push_back(arr[i + 1]);
    }
    
    int leftover = -1;//for odd numbers(impar)
    bool hasLeftover = false;
    if (arr.size() % 2 != 0) 
    {
        leftover = arr.back();
        hasLeftover = true;
    }

    fordJohnsonSortVector(sorted);//Recursively

    //Insert the larger elements of each pair in order
    for (size_t i = 0; i + 1 < arr.size(); i += 2) 
    {
        // int larger = (arr[i] > arr[i + 1]) ? arr[i] : arr[i + 1];
        int larger;
        if (arr[i] > arr[i + 1])
            larger = arr[i];
        else
            larger = arr[i + 1];
        binaryInsertVector(sorted, larger);
    }

    //Insert leftover if there was one
    if (hasLeftover)
        binaryInsertVector(sorted, leftover);

    //Copy back
    arr = sorted;
}
void PmergeMe::fordJohnsonSortDeque(std::deque<int> &d) 
{
    if (d.size() <= 1) return;

    std::deque<int> sorted;
    for (size_t i = 0; i + 1 < d.size(); i += 2) 
    {
        if (d[i] < d[i + 1])
            sorted.push_back(d[i]);
        else
            sorted.push_back(d[i + 1]);
    }

    int leftover = -1;
    bool hasLeftover = false;
    if (d.size() % 2 != 0) {
        leftover = d.back();
        hasLeftover = true;
    }

    fordJohnsonSortDeque(sorted);

    for (size_t i = 0; i + 1 < d.size(); i += 2) 
    {
        int larger;
        if (d[i] > d[i + 1])
            larger = d[i];
        else
            larger = d[i + 1];
        binaryInsertDeque(sorted, larger);
    }
    if (hasLeftover)
        binaryInsertDeque(sorted, leftover);

    d = sorted;
}

void PmergeMe::sortVector() 
{
    fordJohnsonSortVector(numbersVector_);
}

void PmergeMe::sortDeque() 
{
    fordJohnsonSortDeque(numbersDeque_);
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
//How binary works?
// Suppose sorted = {2, 4, 6, 8} and value = 5.

// low = 0, high = 4
// mid = 2 → sorted[2] = 6
// Since 6 > 5 → high = mid = 2

// low = 0, high = 2
// mid = 1 → sorted[1] = 4
// Since 4 < 5 → low = mid + 1 = 2

// low = 2, high = 2 → loop ends

// Insert at index 2 → sorted = {2, 4, 5, 6, 8} ✅
