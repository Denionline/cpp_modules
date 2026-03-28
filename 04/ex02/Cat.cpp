#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Wow there is a " << getType() << " here :)" << std::endl;
}

Cat::Cat( const std::string newType ) {
	type = newType;
	brain = new Brain();
	std::cout << "Wow there is a " << getType() << " here :)" << std::endl;
}

Cat::Cat( const Cat& copy ) {
	std::cout << "An " << getType() << " was copied" << std::endl;
	*this = copy;
}
Cat&	Cat::operator=( const Cat& copy ) {
	std::cout << "The " << copy.getType() << " now is " << copy.type << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << "The " << getType() << " passed away :(" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << YELLOW << BOLD << std::endl;
	std::cout << "_._     _,-'""`-._" << std::endl;
	std::cout << "(,-.`._,'(       |\\`-/|" << std::endl;
	std::cout << "    `-.-' \\ )-`( , o o) " << CYAN << "Meow" << YELLOW << std::endl;
	std::cout << "          `-    \\`_`\"'-" << std::endl;
	std::cout << RESET << std::endl;
}

void	Cat::thinkSound( void ) {
	brain->newIdea("Meow");
}

void	Cat::forgotSound( void ) {
	brain->forgotIdea();
}

void	Cat::showThoughts( void ) {
	brain->showIdeas();
}