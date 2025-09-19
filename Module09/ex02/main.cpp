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

        //Parse CLI arguments and fill containers
        sorter.parseInput(argc, argv);

        //Print before sorting
       //std::cout << "Before sorting:" << std::endl;
        sorter.printBefore();  // Calls both printBeforeVector and printBeforeDeque
        
        //Print after sorting
       //std::cout << "After sorting:" << std::endl;
        sorter.printAfter();   // Calls both printAfterVector and printAfterDeque
        
        //Sort and measure
        sorter.measureVectorSort();
        sorter.measureDequeSort();

        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
