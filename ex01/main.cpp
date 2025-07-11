#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	// Basic test
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// Test: Exception when adding more than capacity
	try {
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << "Exception caught (addNumber): " << e.what();
	}

	// Test: Exception when not enough numbers for span
	Span sp2(2);
	sp2.addNumber(1);
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught (shortestSpan): " << e.what();
	}
	try {
		std::cout << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught (longestSpan): " << e.what();
	}

	// Test: Large input
	Span sp3(10000);
	for (int i = 0; i < 10000; ++i)
		sp3.addNumber(i);
	std::cout << "Large input shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Large input longest span: " << sp3.longestSpan() << std::endl;

	// Test: Negative numbers
	Span sp4(3);
	sp4.addNumber(-10);
	sp4.addNumber(0);
	sp4.addNumber(10);
	std::cout << "Negative numbers shortest span: " << sp4.shortestSpan() << std::endl;
	std::cout << "Negative numbers longest span: " << sp4.longestSpan() << std::endl;

	return 0;
}