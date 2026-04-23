#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stack>

class RPN {
	private:
		std::deque<char>	_data;
	public:
		RPN();
		RPN( std::string );
		RPN( const RPN& );
		RPN&	operator=( const RPN& );
		~RPN();

	void	resolveNotation( void );

	class ExceptionError: public std::exception {
		public:
			virtual const char*	what() const throw() {
				return ("Error");
			}
	};
};
