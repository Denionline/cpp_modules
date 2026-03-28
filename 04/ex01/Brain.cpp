#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < MAX_IDEAS; i++) this->ideas[i] = "";
	std::cout << BOLD << CYAN << "Start to think" << RESET << std::endl;
}

Brain::Brain( std::string *ideas ) {
	std::cout << BOLD << CYAN << "Start to think with some ideas" << RESET << std::endl;
	if (sizeof(this->ideas) != sizeof(ideas)) {
		std::cout << "Invalid size of array" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_IDEAS; i++) this->ideas[i] = ideas[i];
}

Brain::Brain( const Brain& copy ) {
	std::cout << BOLD << CYAN << "Copy brain ideas" << RESET << std::endl;
	*this = copy;
}

Brain&	Brain::operator=( const Brain& copy ) {
	std::cout << BOLD << CYAN << "Assigned brain ideas" << RESET << std::endl;
	if (this != &copy) {
		for (int i = 0; i < MAX_IDEAS; i++) {
			this->ideas[i] = copy.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << BOLD << YELLOW << "Stop to think" << RESET << std::endl;
}

void	Brain::newIdea( std::string newIdea ) {
	for (int i = 0; i < MAX_IDEAS; i++) {
		if (ideas[i].empty()) {
			ideas[i] = newIdea;
			return;
		}
	}
	std::cout << RED << "HEADACHE" << RESET << " a lot of ideas to remember" << std::endl;
}

void	Brain::forgotIdea( void ) {
	if (!ideas[0].empty()) {
		ideas[0] = "";
		return;
	}
	for (int i = 0; i < MAX_IDEAS - 1; i++) {
		if (ideas[i].empty() && !ideas[i + 1].empty()) {
			ideas[i + 1] = "";
			return;
		}
	}
	std::cout << GREEN << "PEACE" << RESET << " no ideas to remember" << std::endl;
}

void	Brain::showIdeas( void ) {
	for (int i = 0; i < MAX_IDEAS; i++) {
		if (!ideas[i].empty()) {
			std::cout << "[" << (i + 1) << "] " << ideas[i] << std::endl;
		}
	}
}
