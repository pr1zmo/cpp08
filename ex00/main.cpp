// test_easyfind_extended.cpp
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <string>
#include "easyfind.hpp"


int main()
{
	// vector<int>
	{
		std::vector<int> v;
		for (int i = 1; i <= 5; ++i)
			v.push_back(i);
		try {
			std::vector<int>::iterator it = easyfind(v, 3);
			std::cout << "vector<int>: found " << *it << "\n";
		} catch (const std::exception& e) {
			std::cout << "vector<int>: " << e.what();
		}
		try {
			easyfind(v, 42);
			std::cout << "vector<int> absent: no exception\n";
		} catch (const std::exception& e) {
			std::cout << "vector<int> absent: " << e.what();
		}
	}

	// list<int>
	{
		std::list<int> l;
		for (int i = 1; i <= 5; ++i)
			l.push_back(i);
		try {
			std::list<int>::iterator it = easyfind(l, 5);
			std::cout << "list<int>: found " << *it << "\n";
		} catch (const std::exception& e) {
			std::cout << "list<int>: " << e.what();
		}
		try {
			easyfind(l, 0);
			std::cout << "list<int> absent: no exception\n";
		} catch (const std::exception& e) {
			std::cout << "list<int> absent: " << e.what();
		}
	}

	// deque<int>
	{
		std::deque<int> d;
		for (int i = 10; i <= 50; i += 10)
			d.push_back(i);
		try {
			std::deque<int>::iterator it = easyfind(d, 30);
			std::cout << "deque<int>: found " << *it << "\n";
		} catch (const std::exception& e) {
			std::cout << "deque<int>: " << e.what();
		}
		try {
			easyfind(d, 99);
			std::cout << "deque<int> absent: no exception\n";
		} catch (const std::exception& e) {
			std::cout << "deque<int> absent: " << e.what();
		}
	}

	// set<int>
	{
		std::set<int> s;
		for (int i = 1; i <= 5; ++i)
			s.insert(i * 2);
		try {
			std::set<int>::iterator it = easyfind(s, 4);
			std::cout << "set<int>: found " << *it << "\n";
		} catch (const std::exception& e) {
			std::cout << "set<int>: " << e.what();
		}
		try {
			easyfind(s, 3);
			std::cout << "set<int> absent: no exception\n";
		} catch (const std::exception& e) {
			std::cout << "set<int> absent: " << e.what();
		}
	}

	// vector<double>
	{
		std::vector<double> vd;
		vd.push_back(1.0);
		vd.push_back(2.5);
		vd.push_back(3.0);
		try {
			std::vector<double>::iterator it = easyfind(vd, 3);
			std::cout << "vector<double>: found " << *it << "\n";
		} catch (const std::exception& e) {
			std::cout << "vector<double>: " << e.what();
		}
		try {
			easyfind(vd, 42);
			std::cout << "vector<double> absent: no exception\n";
		} catch (const std::exception& e) {
			std::cout << "vector<double> absent: " << e.what();
		}
	}

	// *vector<string> — expected compile-time error
	// try
	// {
	// 	std::vector<std::string> vs;
	// 	vs.push_back("1");
	// 	vs.push_back("2");
	// 	std::vector<std::string>::iterator it = easyfind(vs, 2); // error: no operator==(std::string, int)
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << "vector<string>: " << e.what() << "\n";
	// }

	// // *map<int,int> — expected compile-time error
	// try{
	// 	std::map<int,int> m;
	// 	m[1] = 10;
	// 	std::map<int,int>::iterator it = easyfind(m, 1); // error: no nested iterator over mapped_type
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << "map<int,int>: " << e.what() << "\n";
	// }

	return 0;
}
