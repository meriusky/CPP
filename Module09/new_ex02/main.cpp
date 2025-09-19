#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        if (!PmergeMe::isPositiveInteger(argv[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int value = std::atoi(argv[i]);
        vec.push_back(value);
        deq.push_back(value);
    }

    std::cout << "Before: ";
    PmergeMe::printSequence(vec);

    PmergeMe sorter;

    clock_t start = clock();
    sorter.sortVector(vec);
    clock_t end = clock();
    std::cout << "After: ";
    PmergeMe::printSequence(vec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

    start = clock();
    sorter.sortDeque(deq);
    end = clock();
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

    return 0;
}

