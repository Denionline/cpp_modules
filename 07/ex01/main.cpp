#include "iter.hpp"

void	toUpperString( char* &s ) {
	if (!s) return;
	for (size_t i = 0; s[i]; i++) s[i] = ::toupper(s[i]);
}

void	printString( const std::string &s ) {
	if (s.empty()) return;
	std::cout << "printString called to print: " << s << std::endl;
}

void	sumNumbers( int& n ) {
	n += 10;
}

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);

	if (argc) {
		::iter(argv, (size_t)argc, toUpperString);
		std::cout << "argv = {";
		for (int i = 0; i < argc; i++) std::cout << argv[i] << ((i + 1) < argc ? ", " : "");
		std::cout << "}" << std::endl;
	}


	int	numbers[] = {1, 2, 3, 4, 5};
	int	size = sizeof(numbers) / sizeof(numbers[0]);

	::iter(numbers, size, sumNumbers);
	std::cout << "numbers = {";
	for (int i = 0; i < size; i++) std::cout << numbers[i] << ((i + 1) < size ? ", " : "");
	std::cout << "}" << std::endl;

	const std::string	apple = "Apple";
	const std::string	banana = "Banana";
	std::string				fruits[] = {apple, banana};
	size_t						lfruits = sizeof(fruits) / sizeof(*fruits);

	::iter(fruits, lfruits, printString);
}
