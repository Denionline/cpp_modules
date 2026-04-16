#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>

template<typename T>
typename T::iterator	easyfind( T& t , int n ) {
	for (typename T::iterator idx = t.begin(); idx != t.end(); idx++) {
		if (*idx == n) return idx;
	}
	throw std::logic_error("Not found a value");
}

template<typename T>
typename T::const_iterator	easyfind( const T& t , int n ) {
	for (typename T::const_iterator idx = t.begin(); idx != t.end(); idx++) {
		if (*idx == n) return idx;
	}
	throw std::logic_error("Not found a value");
}