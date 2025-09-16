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
        std::string expr = argv[1];
        RPN rpn(expr);

        int result = rpn.evaluate();
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/*#include <iostream>
#include <string>
#include <cstdlib>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)//argument check
    {
        std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
        return 1;
    }

    std::string expr = argv[1];//store input by convertinc the string into a std::string
//Evaluate the expression: Creation RPN with the input expression
    try
    {
        RPN rpn(expr);
        int result = rpn.evaluate();//Processing the expression using stack
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}*/

