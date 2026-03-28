#include "Animal.hpp"

// Orthodoxal
Animal::Animal(): type("Animal") {
	std::cout << "Some " << getType() << " appeared!" << std::endl;
}

Animal::Animal( const std::string newType ): type(newType) {
	std::cout << "Some " << getType() << " appeared!" << std::endl;
}

Animal::Animal( const Animal& copy ) {
	std::cout << "An " << type << " was copied" << std::endl;
	*this = copy;
}
Animal&	Animal::operator=( const Animal& copy ) {
	std::cout << "The " << this->type << " now is " << copy.type << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "The animal " << getType() << " was destructed" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (RED + this->type + RESET);
}

void	Animal::makeSound( void ) const {
	std::cout << std::endl;
	std::cout << "      .-." << std::endl;
	std::cout << "     (o.o)" << std::endl;
	std::cout << "      |=|" << std::endl;
	std::cout << "     __|__" << std::endl;
	std::cout << "   //.=|=.\\\\" << std::endl;
	std::cout << "  // .=|=. \\\\      " << BOLD << CYAN << "404 Sound not found" << RESET << std::endl;
	std::cout << "  \\\\ .=|=. //" << std::endl;
	std::cout << "   \\\\(_=_)//" << std::endl;
	std::cout << "    (:| |:)" << std::endl;
	std::cout << "     || ||" << std::endl;
	std::cout << "     () ()" << std::endl;
	std::cout << "     || ||" << std::endl;
	std::cout << "     || ||" << std::endl;
	std::cout << "    ==' '==" << std::endl;
	std::cout << std::endl;
}
