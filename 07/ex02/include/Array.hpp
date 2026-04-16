#pragma once

#include <exception>
#include <iostream>
#include <cstddef>

template<typename T>
class Array {
		private:
			T*					_array;
			__uint32_t	_length;
		public:
			Array(): _array(new T[0]), _length(0)
			{}
			Array( __uint32_t n ): _array(new T[n]), _length(n)
			{}
			Array( Array& copy ) {
				*this = copy;
			}
			Array&	operator=( const Array& copy ) {
				if (this != &copy) {
					this->_array = copy._array;
					this->_length = copy._length;
				}
				return (*this);
			}
			~Array()
			{}

			T&	operator[]( __uint32_t idx ) {
				if (idx < 0 || idx >= _length) throw OutOfBounds();
				return (_array[idx]);
			}

			__uint32_t	size( void ) {
				return (_length);
			}

			class OutOfBounds: public std::exception {
				public:
					const char* what() const throw() {
						return ("Index is out of bounds!");
					}
			};
};
