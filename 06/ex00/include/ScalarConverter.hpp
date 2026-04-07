#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

class ScalarConverter {
	public:
		virtual ~ScalarConverter() = 0;
		static void	convert( const std::string& );
};