
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialForm", 25, 5),
	_target("Presidential")
{}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& f ):
	AForm(f.getName(), f.getSignGrade(), f.getExecuteGrade()),
	_target(f._target)
{}


PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy ) {
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string	PresidentialPardonForm::getTarget( void ) const {
	return (CYAN + this->_target + RESET);
}

void	PresidentialPardonForm::execute( const Bureaucrat& b ) const {
	try {
		if (!getIsSigned())
			throw AForm::FormIsNotSigned();
		if (b.getGrade() > this->getExecuteGrade())
			throw AForm::GradeTooLowException();
		std::cout
		<< "Informs that "
		<<	getTarget()
		<< " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
}