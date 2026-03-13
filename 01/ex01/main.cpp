#include "Zombie.hpp"

static bool	isNumber(std::string str) {
	const int	size = str.length();

	for (int i = 0; i < size; i++) {
		if (!std::isdigit(str[i])) return (false);
	}
	return (true);
}

int main(int argc, char *argv[]){
	(--argc, ++argv);

	std::string	number = argc > 0 ? argv[0] : "1";
	std::string	name = argc > 1 ? argv[1] : "Foo";

	if (number.length() > 5 || !isNumber(number)) {
		std::cout << "The first param must to be a valid number!" << std::endl;
		return (1);
	}

	long	N = std::strtol(number.c_str(), NULL, 10);
	Zombie	*horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
