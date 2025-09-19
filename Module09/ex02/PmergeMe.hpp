#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> numbersVector_;
        std::deque<int>  numbersDeque_;

        // Sorting algorithms
        void mergeInsertSortVector(std::vector<int> &v);
        void mergeInsertSortDeque(std::deque<int> &d);

        // Binary insert helpers
        void binaryInsertVector(std::vector<int> &sorted, int value);
        void binaryInsertDeque(std::deque<int> &sorted, int value);

        // Utility
        bool isNumber(const std::string &str) const;

        // Printing helpers
        void printBeforeVector() const;
        void printBeforeDeque() const;
        void printAfterVector() const;
        void printAfterDeque() const;

    public:
        // Canonical
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        // Input
        void parseInput(int argc, char **argv);

        // Sort
        void sortVector();
        void sortDeque();

        // Printing wrappers
        void printBefore() const;
        void printAfter() const;

        // Timing
        void measureVectorSort();
        void measureDequeSort();
};

#endif
//CLI arguments = Command Line Interference arguments
//The are the words we type after the program's name when running it from the terminal
//Exemple: ./PmergeMe->compiler 1 3 4 6-> the CLI
