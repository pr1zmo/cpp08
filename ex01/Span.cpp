#include "Span.hpp"
#include <iostream>
#include <limits>

Span::Span()
	: _N(0), _span(), _size(0) {
}

Span::Span(unsigned int n)
	: _N(n), _span() , _size(0) {
}

Span::Span(const Span& other)
	: _N(other._N), _span(other._span), _size(other._size) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_N = other._N;
		this->_span = other._span;
		this->_size = other._size;
	}
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int n){
	if (this->_size == this->_N)
		throw std::length_error("Span size exceeded\n");
	this->_span.push_back(n);
	this->_size++;
}

int Span::shortestSpan(void) const{
	int old_res = std::numeric_limits<unsigned int>::max();
	int res;
	if (this->_size <= 1)
		throw std::logic_error("Not enough numbers\n");
	for (int i = 0; i < (int)this->_size; i++){
		for (int k = i + 1 ; k < (int)this->_size; k++)
		{
			res = abs(this->_span.at(i) - this->_span.at(k));
			res > old_res ? res = old_res : res; 
		}
	}
	return res;
}

int Span::longestSpan(void) const{
	int old_res = 0;
	int res;
	if (this->_size <= 1)
		throw std::logic_error("Not enough numbers\n");
	for (int i = 0; i < (int)this->_size; i++){
		for (int k = i + 1 ; k < (int)this->_size; k++)
		{
			res = abs(this->_span.at(i) - this->_span.at(k));
			res < old_res ? res = old_res : old_res = res; 
		}
	}
	return res;
}