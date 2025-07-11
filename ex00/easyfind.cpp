#include "easyfind.hpp"
#include <iostream>

template <typename T>
easyfind<T>::easyfind() {
	std::cout << "easyfind: Default constructor called" << std::endl;
}

template <typename T>
easyfind<T>::easyfind(const easyfind& other)
	: _target(other._target) {
	std::cout << "easyfind: Copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
easyfind<T>& easyfind::operator=(const easyfind& other) {
	std::cout << "easyfind: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		this->_target = other._target;
	}
	return *this;
}

template <typename T>
easyfind<T>::~easyfind() {
	std::cout << "easyfind: Destructor called" << std::endl;
}