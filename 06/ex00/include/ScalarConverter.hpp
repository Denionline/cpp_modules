#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <exception>

enum eType {
	CHAR = 'c',
	INT = 'i',
	FLOAT = 'f',
	DOUBLE = 'd'
};

class ScalarConverter {
	public:
		virtual ~ScalarConverter() = 0;
		static void	convert( const std::string& );

		class NumberTooLarge: public std::exception {
			public:
				const char* what() const throw() {
					return ("Number too large");
				}
		};
};