#include "MutantStack.hpp"
#include <iostream>
#include <stack>
/*
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
*/
int main()
{
	std::cout << "---👾Creating MutantStack👾---" << std::endl;
    MutantStack<int> mstack;
	
	//Pushing elements
	std::cout << "---🛸Pushing elemets🛸--- " << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top check: " << mstack.top() << std::endl; // 17
	//removing the last element (17)
    mstack.pop();
    std::cout << "Size check: " << mstack.size() << std::endl; // 1

	std::cout << "---🛸Pushing MORE elements🛸---" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
	//Now stack contais (from bottom to top) 5, 3, 5, 737, 0
	
	std::cout << "---🚀Iteration check🚀---" << std::endl;
    std::cout << "Elements:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
    while( it != mstack.end())
	{
        std::cout << *it << std::endl;
		it++;
	}

    std::stack<int> s(mstack); // copy works
    return 0;
}
// What does it mean STL container is not iterable?
//	An iterable conteiner is one where you can traverse ist element, for exemple with a loog using
// 	iterators like begin() -> end(). Most STL Containers (vector, list, deque...) provide 
// 	begin() and end() and you can easly walk throught them.
// 	But std::stack NO, only lets you access top(), push(), pop(), size()
