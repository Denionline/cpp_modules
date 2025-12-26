#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; argv[i] ; i++) {
			std::string string = argv[i];
			for (unsigned long j = 0; j < string.size(); j++) {
				std::cout << (char)toupper(string[j]);
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
