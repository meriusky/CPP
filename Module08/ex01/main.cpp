#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    std::cout << "---- Small test ----" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl; // 2
    std::cout << sp.longestSpan() << std::endl;  // 14

    std::cout << "---- Range test ----" << std::endl;
    Span sp2(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++)
        v.push_back(std::rand());

    sp2.addRange(v.begin(), v.end());

    std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp2.longestSpan() << std::endl;

    return 0;
}
//GOAL: Understand how to combine multiple C++ concepts into  single usefull class.
//Dynamic storage with STL: Instead of a logit array I use std::vector and control capacity (with the _N hehe)

