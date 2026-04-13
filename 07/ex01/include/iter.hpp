#pragma once

#include <iostream>

template<typename T>
void	iter( T* array , const T length , T(f(T)) ) {
	for (size_t i = 0; i < length; i++) f(array);
}
