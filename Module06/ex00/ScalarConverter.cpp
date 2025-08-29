#include "ScalarConverter.hpp"

static bool isCharLiteral(const std::string& s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isIntLiteral(const std::string& s) {
    char* end;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0') return false;
    if (errno == ERANGE || val < INT_MIN || val > INT_MAX) return false;
    return true;
}

static bool isFloatLiteral(const std::string& s) {
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    if (s[s.size() - 1] != 'f') return false;
    char* end;
    errno = 0;
    std::strtof(s.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDoubleLiteral(const std::string& s) {
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;
    char* end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    if (isCharLiteral(literal)) {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (isIntLiteral(literal)) {
        int i = std::atoi(literal.c_str());
        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        if (f >= 32 && f <= 126 && literal != "nanf" && literal != "+inff" && literal != "-inff")
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (d >= 32 && d <= 126 && literal != "nan" && literal != "+inf" && literal != "-inf")
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (literal == "nan" || literal == "+inf" || literal == "-inf")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    std::cout << "Unrecognized literal: " << literal << std::endl;
}

