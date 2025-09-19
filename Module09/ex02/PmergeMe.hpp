#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>//for handling CLI arguments
#include <iostream>
#include <stdexcept>//throwing errors (std::runtime_error)
#include <ctime>//to measure execution time (clock())

class PmergeMe
{
    private:
        std::vector<int> numbersVector_;
        std::deque<int>  numbersDeque_;

        //Sorting algorithms: implement Ford-Johnson sort
        void mergeInsertSortVector(std::vector<int> &v);//take & to modify the container directly
        void mergeInsertSortDeque(std::deque<int> &d);

        //Binary insert helpers: help insert numbers into stored sequence using binary search
        //Like asubrutine used by mergeInsertSort...
        void binaryInsertVector(std::vector<int> &sorted, int value);
        void binaryInsertDeque(std::deque<int> &sorted, int value);

        //Checks if a string is valid positive integer
        bool isNumber(const std::string &str) const;

        //Printing helpers
        void printBeforeVector() const;//const bc they don't change objects
        void printBeforeDeque() const;
        void printAfterVector() const;
        void printAfterDeque() const;

    public:
        PmergeMe();//creates empty object
        PmergeMe(const PmergeMe &other);//allows copy PmergeMe objects
        PmergeMe& operator=(const PmergeMe &other);//allows to do assignment obj1 = obj2
        ~PmergeMe();

        //Input: Takes input the fills
        void parseInput(int argc, char **argv);

        //Sort: they call the merge-insert sort
        void sortVector();
        void sortDeque();

        //Printing wrappers: for before and after, they call teh private helper printers
        void printBefore() const;
        void printAfter() const;

        //Timing: Run the sorting algorithm and measure how long it takes
        void measureVectorSort();
        void measureDequeSort();
};

#endif
//CLI arguments = Command Line Interference arguments
//The are the words we type after the program's name when running it from the terminal
//Exemple: ./PmergeMe->compiler 1 3 4 6-> the CLI
