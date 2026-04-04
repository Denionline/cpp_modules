#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(1) {}

Bureaucrat::Bureaucrat( const std::string name ): _name(name), _grade(1) {}

Bureaucrat::Bureaucrat( const size_t grade ): _name("Bureaucrat") {
	try {
		if (grade < maxGrade)
			throw GradeTooHighException();
		if (grade > minGrade)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( const std::string name, const size_t grade ): _name(name) {
	try {
		if (grade < maxGrade)
			throw GradeTooHighException();
		if (grade > minGrade)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) {
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy ) {
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName( void ) {
	return (this->_name);
}

size_t		Bureaucrat::getGrade( void ) {
	return (this->_grade);
}

void	Bureaucrat::increaseGrade( void ) {
	try {
		if ((_grade - 1) < maxGrade)
			throw GradeTooHighException();
		_grade -= 1;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decreaseGrade( void ) {
	try	{
		if ((_grade + 1) > minGrade)
			throw GradeTooLowException();
		_grade += 1;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<( std::ostream& o , Bureaucrat& b ) {
	return (o << b.getName() << ", bureaucrat grade " << b.getGrade());
}