#include "Array.hpp"

int	main( void ) {
	try {
		Array<std::string>	fruits(3);

		fruits[0] = "Apple";
		fruits[1] = "Banana";
		fruits[2] = "Grapes";

		__int32_t size = fruits.size();

		std::cout << "array[" << size << "] {";
		for (__int32_t i = 0; i < size; i++) {
			std::cout << fruits[i] << ((i + 1) < size ? ", " : "");
		}
		std::cout << "}" << std::endl;

		std::cout << fruits[3] << std::endl;
	}
	catch( const std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
}
