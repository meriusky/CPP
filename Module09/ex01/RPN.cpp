#include "RPN.hpp"
#include <cstdlib>
#include <cctype>

// Default constructor
RPN::RPN() : expression_("") {}

// Constructor with expression
RPN::RPN(const std::string &expr) : expression_(expr) {}

// Copy constructor
RPN::RPN(const RPN &other) : expression_(other.expression_) {}

// Assignment operator
RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        expression_ = other.expression_;
    return *this;
}

// Destructor
RPN::~RPN() {}

// Evaluate the stored RPN expression
int RPN::evaluate()
{
    std::stack<int> s;
    std::istringstream iss(expression_);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0])) // single-digit number
        {
            s.push(token[0] - '0');
        }
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                       token[0] == '*' || token[0] == '/'))
        {
            if (s.size() < 2)
                throw std::runtime_error("Error: not enough operands");

            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (token[0])
            {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error: division by zero");
                    s.push(a / b);
                    break;
            }
        }
        else
        {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (s.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression");

    return s.top();
}

/*#include <sstream> // for std::istringstream
#include <cstdlib> // for atoi

RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}

// Evaluate an RPN expression
int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);//Split the input by spaces (each is (0-9) or (+ _ / *)
    std::string token;

    while (iss >> token)
    {
        //If token is a number
        if (token.size() == 1 && isdigit(token[0]))
        {
            _stack.push_back(token[0] - '0'); //convert char to int and store them in _stack
        }
        // If token is an operator
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int b = _stack.back();//last number of the stack
            _stack.pop_back();//and removeit
            int a = _stack.back();//takes the new last number
            _stack.pop_back();//and removeit as well

            int result;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                result = a / b;
            }
            _stack.push_back(result);
        }
        else
        {
            throw std::runtime_error("Error"); // invalid token
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.back();
}*/

