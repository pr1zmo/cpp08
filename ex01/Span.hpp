#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
	private:
		// int _size;
		unsigned int _N;
		std::vector<int> _span;
		unsigned int _size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif
