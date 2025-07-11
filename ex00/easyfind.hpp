#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class nonExistantElementException : public std::exception{
	public:
		const char* what() const throw() {return "Element doesn't exists\n";};
};

template <typename T>
typename T::iterator	easyfind(T &elems, int el)
{
	typename T::iterator it = std::find(elems.begin(), elems.end(), el);
	if (it == elems.end())
		throw nonExistantElementException();
	else
		return it;
}

#endif