#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
	if (this != &copy) return (*this);
	return (*this);
}

Intern::~Intern(){}

AForm*	Intern::makeForm( std::string formName , std::string target) {
	try {
		if (!(formName == "ShrubberyCreationForm" || formName == "RobotomyRequestForm" || formName == "PresidentialPardonForm"))
			throw FormNameNotFound();
		switch (*formName.c_str()) {
			case 'S':
				return (new ShrubberyCreationForm(target));
			case 'R':
				return (new RobotomyRequestForm(target));
			case 'P':
				return (new PresidentialPardonForm(target));
			default:
				throw FormNameNotFound();
		}
	}
	catch ( const std::exception& e ) {
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}