#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>// The two required containers
#include <deque>// ""                       ""
#include <string>//for parsing and output
#include <iostream>// ""             ""
#include <stdexcept>//for throwing errors
#include <ctime>    // for clock()

class PmergeMe
{
	private:
        // Data storage
        std::vector<int> numbersVector_;//Store sequence in a vector
        std::deque<int>  numbersDeque_;// ""               "" deque

        // The actual Ford-Johnson (merge-insert) recursive algorithms
        void mergeInsertSortVector(std::vector<int> &v);//recursive Ford-Johnson
        void mergeInsertSortDeque(std::deque<int> &d);//
        // Utility: binary insertion:Helper for inserting in sorted order
        void binaryInsertVector(std::vector<int> &sorted, int value);        
		void binaryInsertDeque(std::deque<int> &sorted, int value);
        // Validation:check if an input number string is a valid positive integer
        bool isNumber(const std::string &str) const;

    public:
        // Constructors
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        // Parsing input arguments into containers
        void parseInput(int argc, char **argv);//parse CLI arguments and fill both containers

        // Sorting functions: call the algorithm for each container
        void sortVector();
        void sortDeque();

        // Printing functions
		void printBefore() const
		{
    		printBeforeVector();
    		printBeforeDeque();
		}

		void printAfter() const
		{
    		printAfterVector();
    		printAfterDeque();
		}

//		void printBeforeVector() const;
//		void printBeforeDeque() const;
//		void printAfterVector() const;
//		void printAfterDeque() const;
 //       void printBefore() const;
//        void printAfter() const; 

        // Timing wrappers: to run the sort and the measure time
        void measureVectorSort();
        void measureDequeSort();

 };

#endif
//CLI arguments = Command Line Interference arguments
//The are the words we type after the program's name when running it from the terminal
//Exemple: ./PmergeMe->compiler 1 3 4 6-> the CLI
