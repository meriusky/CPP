#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
//Checks default constructos works -> makes an empty array
		std::cout << "----Default constructor check✅----" << std::endl;
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

//Size constructor works -> created 5 integer(defaul initialize to 0) and thes modified by the main. Before empy after with numbers.
		std::cout << "----Size constructor check✅----" << std::endl;
        Array<int> numbers(5);
        std::cout << "Numbers size: " << numbers.size() << std::endl;
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "Numbers: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

//Copy constructor works -> the new Array got the same values NOT JUST A POINTER TO THE SAME MEMORY
		std::cout << "----Copy constructor check✅----" << std::endl;
        Array<int> copy(numbers);
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

//Deep copy working: the modification does not affect the original
		std::cout << "----Deep copy check✅----" << std::endl;
        copy[0] = 999;
        std::cout << "Modified copy[0]: " << copy[0] << std::endl;
        std::cout << "Original numbers[0]: " << numbers[0] << std::endl;

//Testing that the template function works with std::string too, proves that is generic :)
		std::cout << "----Template function working with string check✅----" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "Array";
        words[2] = "Template";
        std::cout << "Words: ";
        for (unsigned int i = 0; i < words.size(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

//Test out-of-bounds access
		std::cout << "---- out of bounds check✅----" << std::endl;
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
