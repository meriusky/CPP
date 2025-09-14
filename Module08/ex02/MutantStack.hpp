#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>//class template thet inherits from std::stack<T>
{
	public:
//Constructor: calls default constructor of std::stack and creates empty stack
    	MutantStack() : std::stack<T>() {}
//cpy constructor: Initializes the new stack with the content other
    	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    	MutantStack& operator=(const MutantStack& other)
    	{
			//calls the asigment operator of the base class std::stack which knows how to 
			//copy ist internal conteiner
        	std::stack<T>::operator=(other);
        	return *this;//now we can chain assigment like a = b = c;)
    	}
    	~MutantStack() {}

    //Declaring typedefs for iterator types using the underlying container
    	typedef typename std::deque<T>::iterator iterator;
    	typedef typename std::deque<T>::const_iterator const_iterator;
    	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    //std::stack dosen't expose iterators itself, but has a protected member called 'c' 
	//which is underlying conteiners (by default std::deque<T>), this conteiner does 
	//support iterators.
    	iterator begin() { return this->c.begin(); }// {protected member inside std::stack}
    	iterator end() { return this->c.end(); }
    	const_iterator begin() const { return this->c.begin(); }
    	const_iterator end() const { return this->c.end(); }

    	reverse_iterator rbegin() { return this->c.rbegin(); }
    	reverse_iterator rend() { return this->c.rend(); }
    	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
// How we turn std::stack into an iterable container?
// 	We expose the iterators of the uderlying containers trhough the stack. That way, 
// 	we are doing a costume class that behaves like a stack but also allows iteration.
//
// 	MutantStack uses std::stack as its foundation. We reuse all stack functionallity 
// 	(push, pop, top) and we extended by ading a new feature, the iteration. Instead of building
// 	a container from scratch we take how stack works and ad an extra power🦸
//
//Reverse iterators? 
//	They are not a must have but they helps ordering the stuff in the natural way.
