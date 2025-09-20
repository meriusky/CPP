#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>


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

        //Parse CLI arguments and fill containers
        sorter.parseInput(argc, argv);

        //Print before sorting
       //std::cout << "Before sorting:" << std::endl;
        sorter.printBefore();  // Calls both printBeforeVector and printBeforeDeque
        
        //Sort and measure
        sorter.measureVectorSort();
        sorter.measureDequeSort();

       //Print after sorting
       //std::cout << "After sorting:" << std::endl;
        sorter.printAfter();   // Calls both printAfterVector and printAfterDequeu
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
//GOAL:
//1.Implement a program called PmergeMe that sorts a sequence of positive 
//integers given as command-line arguments.
//2.You must use the Ford–Johnson algorithm (merge-insert sort).
//3.The program must handle large sequences (≥ 3000 integers) efficiently.
//4.Use at least two different STL containers (commonly std::vector and std::deque) 
//to demonstrate performance differences.