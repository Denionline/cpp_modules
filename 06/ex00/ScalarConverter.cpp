#include "ScalarConverter.hpp"

void	ScalarConverter::convert( const std::string& number ) {
	int		nInt = (int)strtol(number.c_str(), NULL, 10);
	float	nFloat = strtof(number.c_str(), NULL);
	double	nDouble = strtod(number.c_str(), NULL);

	std::cout <<  "char: " << static_cast<char>(nInt) << std::endl;
	std::cout <<  "int: " << nInt << std::endl;

	std::cout
	<<  "float: "
	<< std::fixed
	<< std::setprecision(1)
	<< nFloat
	<< "f"
	<< std::endl;

	std::cout
	<<  "double: "
	<< std::fixed
	<< std::setprecision(1)
	<< nDouble
	<< std::endl;
}

/*
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/