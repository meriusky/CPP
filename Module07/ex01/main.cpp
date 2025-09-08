#include <iostream>
#include "iter.hpp"

//sample function to print an element: observes the array
template <typename T>
void printElement(T& elem)
{
    std::cout << elem << " ";
}

//sample function: changes the array
template <typename T>
void increment(T& elem)
{
    elem += 1;
}

int main()
{
    // Test with int array
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Original intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment<int>);
    std::cout << "Incremented intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl << std::endl;

    // Test with string array
    std::string strArray[3] = {"Hello", "World", "!"};
    std::cout << "Original strArray: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    // Just printing again
    std::cout << "strArray unchanged: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
//printelement for what? ➡️ iter funcion only call a function on eahc element, we needit to actually see results.
//increment, for what? ➡️  This function serves a comlementary purpose to printElement. Its importat bc iter can not only rean elements but also modify them
