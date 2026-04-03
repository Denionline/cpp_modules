#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat")
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat( const std::string name ): _name(name)
{}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) {
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy ) {
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName( void ) {
	return (this->_name);
}

size_t		Bureaucrat::getGrade( void ) {
	return (this->_grade);
}

void		Bureaucrat::increaseGrade( void ) {
	const int	max_grade = 150;

	_grade += 1;
	if (_grade >= max_grade) {
		_grade = max_grade;
	};
}

void		Bureaucrat::decreaseGrade( void ) {
	const int	min_grade = 1;

	try	{
		_grade -= 1;
		if (_grade <= min_grade) {

		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


}
