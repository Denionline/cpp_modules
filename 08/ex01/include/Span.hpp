#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>

class Span {
	private:
		std::vector<int>	_numbers;
		size_t						_maxSize;
	public:
		Span( void );
		Span( __int32_t );
		~Span();

		void			addNumber( int );
		void			addMultipleNumbers( int[], size_t );
		void			addMultipleNumbers( std::vector<int> );
		size_t		shortestSpan( void );
		size_t		longestSpan( void );

		void	print( void );
		bool	find_number( size_t );

		class MaxValuesReached: public std::exception {
			public:
				const char *what() const throw() {
					return ("Max values reached");
				}
		};

		class NotEnoughNumbers: public std::exception {
			public:
				const char *what() const throw() {
					return ("Not enough numbers");
				}
		};
};