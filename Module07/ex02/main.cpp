#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        // Empty array
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        // Array of 5 ints
        Array<int> numbers(5);
        std::cout << "Numbers size: " << numbers.size() << std::endl;
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "Numbers: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        // Copy constructor
        Array<int> copy(numbers);
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        // Modify copy, check deep copy
        copy[0] = 999;
        std::cout << "Modified copy[0]: " << copy[0] << std::endl;
        std::cout << "Original numbers[0]: " << numbers[0] << std::endl;

        // Array of strings
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "Array";
        words[2] = "Template";
        std::cout << "Words: ";
        for (unsigned int i = 0; i < words.size(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << "Trying to access words[10]..." << std::endl;
        std::cout << words[10] << std::endl; // should throw
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
//This exercice is about implementign a templeted Array class
