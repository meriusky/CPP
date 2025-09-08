#include <iostream>
#include <string>
#include "Whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;
	std::cout << "a before swap: " << a << ", b before swap: " << b << std::endl;
	std::cout << "🪄swaping🪄" <<  std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
	std::cout << "\nc before swap: " << c << ", d before swap: " << d << std::endl;
	std::cout << "🪄swaping🪄" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
// c is lower bc the are the same exept for the las char and in the ASCII code
// '1' is = 49 and '2' = 50 and 49<50
    return 0;
}

