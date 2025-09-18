#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;

        // Parse CLI arguments and fill containers
        sorter.parseInput(argc, argv);

        // Print before sorting
        std::cout << "Before sorting:" << std::endl;
        sorter.printBefore();  // Calls both printBeforeVector and printBeforeDeque

        // Sort and measure
        sorter.measureVectorSort();
        sorter.measureDequeSort();

        // Print after sorting
        std::cout << "After sorting:" << std::endl;
        sorter.printAfter();   // Calls both printAfterVector and printAfterDeque
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/*
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;

        // Parse input arguments and populate containers
        sorter.parseInput(argc, argv);

        // Print unsorted sequence
        std::cout << "Before: ";
        sorter.printBefore();
        std::cout << std::endl;

        // Sort vector using merge-insert and measure time
        sorter.sortVector();
        std::cout << "After (Vector): ";
        sorter.printAfterVector();
        sorter.measureVectorSort();
        std::cout << std::endl;

        // Sort deque using merge-insert and measure time
        sorter.sortDeque();
        std::cout << "After (Deque): ";
        sorter.printAfterDeque();
        sorter.measureDequeSort();
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}*/

