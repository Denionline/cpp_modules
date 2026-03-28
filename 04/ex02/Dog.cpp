#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Uhuul a " << getType() << " is here :D" << std::endl;
}

Dog::Dog( const std::string newType ) {
	type = newType;
	brain = new Brain();
	std::cout << "Uhuul a " << getType() << " is here :D" << std::endl;
}

Dog::Dog( const Dog& copy ) {
	std::cout << "An " << getType() << " was copied" << std::endl;
	*this = copy;
}
Dog&	Dog::operator=( const Dog& copy ) {
	std::cout << "The " << copy.getType() << " now is " << copy.type << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "OMG the " << getType() << " died :'(" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << GREEN << BOLD << std::endl;
	std::cout << "     |\\_/|                  " << std::endl;
	std::cout << "     | @ @   " << CYAN << "Woof Woof" << GREEN << std::endl;
	std::cout << "     |   <>              _  " << std::endl;
	std::cout << "     |  _/\\------____ ((| |))" << std::endl;
	std::cout << "     |               `--' |   " << std::endl;
	std::cout << " ____|_       ___|   |___.' " << std::endl;
	std::cout << "/_/_____/____/_______|" << std::endl;
	std::cout << RESET << std::endl;
}

void	Dog::thinkSound( void ) {
	brain->newIdea("Woof woof");
}

void	Dog::forgotSound( void ) {
	brain->forgotIdea();
}

void	Dog::showThoughts( void ) {
	brain->showIdeas();
}