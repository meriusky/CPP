#include "ScalarConverter.hpp"

//Check if its char
static bool isCharLiteral(const std::string& s) 
{
    return s.length() == 1 && !std::isdigit(s[0]);
}
/*
static bool isCharLiteral(const std::string& s) 
{
    return s.length() == 3 && s[0] == '\'' && s[2] == '\''; //min 3 char: beginig the char and the end
}*/

//Check if its int
static bool isIntLiteral(const std::string& s) 
{
    char* end;//for pointing the first invalid character
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);//tries to convert string to int base 10
    if (*end != '\0') return false;//if we don't reach the edn of the str, means there were invalid characters(123ab)
    if (errno == ERANGE || val < INT_MIN || val > INT_MAX) return false;//checks if the number overflows the range of regular int
    return true;
}

//Check if its Float (with f at the end)
static bool isFloatLiteral(const std::string& s) 
{
    if (s == "-inff" || s == "+inff" || s == "nanf")//handles special pseudo-literals📍
        return true;
    if (s[s.size() - 1] != 'f') return false;//if the last char is not f ❌
	char* end;
	errno = 0;
    std::strtof(s.c_str(), &end);//tries to parsing the number, valid if parsing consumed all till f and nothing after 
    return (*end == 'f' && *(end + 1) == '\0');
}
//Check if its Bouble
static bool isDoubleLiteral(const std::string& s) 
{
    if (s == "-inf" || s == "+inf" || s == "nan")// handles special pseudo-literals📍
        return true;
    char* end;
    errno = 0;
    std::strtod(s.c_str(), &end);// parsing the double, onlu valid if reached the end
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal) 
{
    std::cout.setf(std::ios::fixed);//set up the output for floating-point numbers
    std::cout.precision(1);//shows 1 decimal digit after the point of float and doubles

    if (isCharLiteral(literal)) 
	{
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (isIntLiteral(literal)) 
	{
        int i = std::atoi(literal.c_str());//converts str in to int
        if (i >= 32 && i <= 126)//ASCII printable
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else// if not, non displayable
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    if (isFloatLiteral(literal)) 
	{
        float f = std::strtof(literal.c_str(), NULL);//converts string in to a float
		//Only prints char if its printable not special value
        if (f >= 32 && f <= 126 && literal != "nanf" && literal != "+inff" && literal != "-inff")
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
		//This to print the specials now
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
		//Prints float itself and converst to double
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    if (isDoubleLiteral(literal)) 
	{
        double d = std::strtod(literal.c_str(), NULL);//converts string to double
		//prints char only if is printable and not special
        if (d >= 32 && d <= 126 && literal != "nan" && literal != "+inf" && literal != "-inf")
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
		//specials cannot be convertet to int
        if (literal == "nan" || literal == "+inf" || literal == "-inf")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
		//Prints float and double values
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
//if non of the above checks pass⬇️
    std::cout << "Unrecognized literal: " << literal << std::endl;
}
//What are pseudo-literals?
//This are part of IEEE754 standard, they are valid representations of unusual numbers thar
//can't be written as normal digits.
