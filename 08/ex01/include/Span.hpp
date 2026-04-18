#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

class Span {
	private:
		std::vector<int>	_numbers;
		__int32_t					_maxSize;
	public:
		Span( void );
		Span( __int32_t );
		~Span();

		void			addNumber( int );
		__int32_t	shortestSpan( void );
		__int32_t	longestSpan( void );

		void	print( void );
};