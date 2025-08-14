#include <iostream>
#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int>
// 	mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

// main.cpp

// main.cpp

#include <stack>
#include <vector>
#include <list>

int main()
{
	// TEST 1: basic MutantStack<int> (default underlying container = deque)
	{
		MutantStack<int> m;
		m.push(5);
		m.push(17);
		std::cout << "m.top() = " << m.top() 
					<< "  // expected 17\n";
		m.pop();
		std::cout << "m.size() = " << m.size() 
					<< "  // expected 1\n";

		m.push(3);
		m.push(5);
		m.push(737);
		m.push(0);
		// expected elements bottom->top: 5,3,5,737,0

		std::cout << "elements (default deque):\n";
		for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << *it << "\n";  // prints 5 3 5 737 0
	}

	// TEST 4: std::stack<int, std::vector<int>> (no iterators)
	{
		std::stack<int, std::vector<int> > sv;
		sv.push(100);
		sv.push(200);
		std::cout << "\nstd::stack<vector> top = " << sv.top() 
					<< "  // expected 200\n";
		sv.pop();
		std::cout << "std::stack<vector> size = " << sv.size() 
					<< "  // expected 1\n";
		// Cannot iterate: no begin()/end()
	}

	// TEST 5: MutantStack const_iterator
	{
		MutantStack<int> mc;
		mc.push(42);
		mc.push(84);
		const MutantStack<int>& cref = mc;
		std::cout << "\nconst MutantStack iteration:\n";
		for (MutantStack<int>::const_iterator cit = cref.begin();
				cit != cref.end(); ++cit)
		{
			std::cout << *cit << "\n";  // prints 42 84
		}
	}

	// TEST 6: empty MutantStack
	{
		MutantStack<int> me;
		if (me.begin() == me.end())
			std::cout << "\nempty MutantStack: begin()==end()  // expected\n";
		// dereferencing me.begin() would be undefined behavior
	}

	return 0;
}
