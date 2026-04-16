#include "Serializer.hpp"

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);
	if (argc != 2) {
		std::cout << "Correct usage: ./exec <string> <number>" << std::endl;
		return (1);
	}

	std::string	name = argv[0], number = argv[1];
	if (name.empty() || number.empty() || number.length() > 5)
		return (1);

	Data		data = (Data){name, strtol(number.c_str(), NULL, 10)};

	uintptr_t	s = Serializer::serialize(&data);

	std::cout << "Serialized struct is => " << s << std::endl;

	data = *Serializer::deserialize(s);

	std::cout
	<< "Data {"
	<< data.name
	<< ", "
	<< data.value
	<< "}"
	<< std::endl;
}
