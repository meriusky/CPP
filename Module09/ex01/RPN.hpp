#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
public:
    RPN();                             // default constructor
    RPN(const std::string &expr);      // constructor with expression
    RPN(const RPN &other);             // copy constructor
    RPN& operator=(const RPN &other);  // assignment operator
    ~RPN();

    int evaluate();                     // evaluate the stored expression

private:
    std::string expression_;            // store the RPN expression
};

#endif

/*
#include <string>
#include <deque>// allows to push_back and op_back like stacks
#include <iostream>
#include <stdexcept>

class RPN
{
	private:
    	std::deque<int> _stack;//container to simulate stack behavior

	public:
    	RPN();
    	RPN(const RPN &other);
    	RPN &operator=(const RPN &other);
    	~RPN();

    	int evaluate(const std::string &expression); //evaluate an RPN expression
//takes the input string, returns the computed integer result
};

#endif*/
//What is a reverse Polish Notation (RPN)?
// Normaly we write 3+4 (infix notation) but RPN you write operands first and then the 
// operator 3 4 +
//
//Which container use?
//	std::deque<int> std::list<int> because RPN evaluation works exactly like a stack
//
//General Algorithm
//1. Split by spaces
//2. For each token: if it's a number 0 to 9 push to the container
//					 if it's operator(+ - / *:): check there are at least 2 num
//					 							 Pop the top two num
//					 							 Apply the operation
//					 							 Push the result back
//3. At the end: if the container has exactly 1 number, that's the result, otherwise error.
//
//Error cases: wrong num of arguments, Invalid tocken ("a" or " "), not enought operands
//            , division by 0, stack not reducen to exactly 1 value at the end
