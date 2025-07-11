#ifndef easyfind_HPP
#define easyfind_HPP

#include <iostream>
#include <algorithm>

template <typename T>

class easyfind {
	public:
		easyfind();
		easyfind(T par1, int par2);
		easyfind(const easyfind& other);
		easyfind& operator=(const easyfind& other);
		~easyfind();
};

// #include "easyfind.tpp"

#endif