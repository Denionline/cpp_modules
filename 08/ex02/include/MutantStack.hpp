#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	private:
		/* data */
	public:
		MutantStack() {}
		~MutantStack() {}
};