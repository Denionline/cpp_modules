#include "WrongAnimal.hpp"

// Orthodoxal
WrongAnimal::WrongAnimal(): type("WrongAnimal") {
	std::cout << "Some " << getType() << " appeared!" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string newType ): type(newType) {
	std::cout << "Some " << getType() << " appeared!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {
	std::cout << "An " << type << " was copied" << std::endl;
	*this = copy;
}
WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& copy ) {
	std::cout << "The " << this->type << " now is " << copy.type << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "The animal " << getType() << " was destructed" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (RED + this->type + RESET);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << std::endl;
	std::cout << "         .-\"\"\"-." << std::endl;
	std::cout << "        /       \\" << std::endl;
	std::cout << "        \\       /" << std::endl;
	std::cout << " .-\"\"\"-.-`.-.-.<  _" << std::endl;
	std::cout << "/      _,-\\ ()()_/:)      " << BOLD << CYAN << "Mama mia not found a sound" << RESET << std::endl;
	std::cout << "\\     / ,  `     `|" << std::endl;
	std::cout << " '-..-| \\-.,___,  /" << std::endl;
	std::cout << "       \\ `-.__/  /" << std::endl;
	std::cout << "        `-.__.-'`" << std::endl;
	std::cout << std::endl;
}
