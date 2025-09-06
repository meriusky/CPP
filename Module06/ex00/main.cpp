#include "ScalarConverter.hpp"

int main(int argc, char** argv) 
{
    if (argc != 2) 
	{
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
//Goal: take a string literal and print its representation
//in the four scalar types: char, int, float and double
//
//Inputs to past to test: "42", "nan", "a", "0.0f"
//
