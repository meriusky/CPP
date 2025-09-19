#include "RPN.hpp"
#include <cstdlib>
#include <cctype>

RPN::RPN() : expression_("") {}//sets expression_ to an empty string
// Constructor with expression
RPN::RPN(const std::string &expr) : expression_(expr) {}//Initializes private member expression_
RPN::RPN(const RPN &other) : expression_(other.expression_) {}//copy constructor
RPN& RPN::operator=(const RPN &other)//copy the asigment operator
{
    if (this != &other)
        expression_ = other.expression_;
    return *this;
}
RPN::~RPN() {}

// Evaluate the stored RPN expression
int RPN::evaluate()
{
    std::stack<int> s;//stack to hold intermediate results during evaluation
    std::istringstream iss(expression_);//For dividing in spaces
    std::string token;//temporary string to store each token

//reads the next whitespace then reads characters up to the next withespace
    while (iss >> token)//reads tokens one by one
    {
        if (token.size() == 1 && std::isdigit(token[0])) // single-digit check
        {
            s.push(token[0] - '0');
        }
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || //operator check
                                       token[0] == '*' || token[0] == '/'))
        {
            if (s.size() < 2)
                throw std::runtime_error("Error: not enough operands");

//top() returns a reference to the top element pop() removes. So get to the top value and removes it
            int b = s.top(); s.pop();//Puts the information in the correct order
            int a = s.top(); s.pop();//so we can operatit as normal( 2 2 + == 2+ 2)

//swich compare that character to each case lebel
            switch (token[0])//Performs the operation and pushes the result
            {
                case '+': s.push(a + b); break;//if match executes push and exits the switch
                case '-': s.push(a - b); break;//like this the operation is pushed into the stack
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

    if (s.size() != 1)//exactly one value check
        throw std::runtime_error("Error: invalid RPN expression");

    return s.top();
}
/*
Whats happening?
1.Tokenize the expression string.
2.For each token:
 If it’s a number → push to stack.
 If it’s an operator → pop two numbers, apply operator, push result back.
 If invalid → throw error.
3.After all tokens:
 If exactly one number remains → that’s the result.
 Otherwise → expression invalid.
