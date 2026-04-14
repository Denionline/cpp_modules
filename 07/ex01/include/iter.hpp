#pragma once

#include <iostream>

class iter {
	private:
		iter();
		iter( const iter& );
		iter&	operator=( const iter& );
		~iter();
};

template<typename T>
void	iter( T* array , size_t length , void (f)(T&) ) {
	for (size_t i = 0; i < length; i++) f(array[i]);
}

template<typename T>
void	iter( T* array , size_t length , void (f)(const T&) ) {
	for (size_t i = 0; i < length; i++) f(array[i]);
}
