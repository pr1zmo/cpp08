#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T>& other);
		MutantStack<T>& operator=(const MutantStack<T>& other);
		~MutantStack<T>();
		
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator 		begin(void);
		const_iterator	begin(void) const;
		iterator			end(void);
		const_iterator	end(void) const;
};

#include "MutantStack.tpp"

#endif