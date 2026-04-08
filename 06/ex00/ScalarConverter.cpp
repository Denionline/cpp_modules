#include "ScalarConverter.hpp"

static bool	numberIsValid( std::string number ) {
	const int	size = number.length();
	int			i;

	for (i = 0; i < size; i++) {
		if ((number.at(i) == '-' || number.at(i) == '+') && (i + 1) != size)
			continue;
		if (number.at(i) == '.' && ++i)
			break;
		if (!std::isdigit(number.at(i)))
			return (false);
	}
	if (i < size && !std::isdigit(number.at(i++)))
		return (false);
	return (i == size || number.at(i) == 'f');
}

static void	print( std::string prefix , std::string number , char t ) {
	const bool	isValid = numberIsValid(number);

	std::cout << prefix;
	switch (t) {
		case CHAR: {
			int	nbr = strtol(number.c_str(), NULL, 10);
			std::cout
			<< ( isValid ?
				( nbr > 31 && nbr < 127 ?
					std::string(1, static_cast<char>(nbr)).c_str()
					: "Non displayable"
				)
				: "impossible"
			);
			break;
		}
		case INT: {
			if (isValid) {
				std::cout << strtol(number.c_str(), NULL, 10);
			} else {
				std::cout << "impossible";
			}
			break;
		}
		case FLOAT: {
			if (isValid) {
				std::cout
				<< std::fixed
				<< std::setprecision(1)
				<< strtof(number.c_str(), NULL)
				<< "f";
			} else {
				std::cout
				<< (number.find('-') == std::string::npos ? "+" : "-")
				<< "inff";
			}
			break;
		}
		case DOUBLE: {
			if (isValid) {
				std::cout
				<< std::fixed
				<< std::setprecision(1)
				<< strtod(number.c_str(), NULL);
			} else {
				std::cout
				<< (number.find('-') == std::string::npos ? "+" : "-")
				<< "inf";
			}
			break;
		}
	}
	std::cout << std::endl;
}

void	ScalarConverter::convert( const std::string& number ) {
	try {
		if (number.length() > 8)
			throw NumberTooLarge();
		print("char: ", number, CHAR);
		print("int: ", number, INT);
		print("float: ", number, FLOAT);
		print("double: ", number, DOUBLE);
	}
	catch( const std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
}
