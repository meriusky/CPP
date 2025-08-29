#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter(); // not instantiable
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    static void convert(const std::string& literal);
};

#endif

