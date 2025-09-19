#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"<RPN_expression>\"" << std::endl;
        return 1;
    }

    try
    {
        std::string expr = argv[1];//takes the input and 
        RPN rpn(expr);//Passes it to the PRN constructor

        int result = rpn.evaluate();//calling evaluate
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)//catch and print the errors
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
//Test: ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
//Test error: ./RPN "3 0 /"  When / is reached. denominator is 0
//Test error: ./RPN "(1 + 1)"


