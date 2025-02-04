#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed b(a);// b has a parameter, so calls fixed with a as a parameter
    Fixed c;
    c = b; //calling the operator
    
    a.setRawBits(42);
    std::cout << "a raw bits: " << a.getRawBits() << std::endl;
 /* std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;*/
    return 0;
}
