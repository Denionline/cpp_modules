#include "Form.hpp"

Form::Form(): _name("Form"), _isSigned(false), _signGrade(5), _executeGrade(1) {}

Form::Form( std::string name ): _name(name), _isSigned(false), _signGrade(1), _executeGrade(1) {}

Form::~Form() {}

Form::Form( const Form& f ): _name(f._name), _isSigned(f._isSigned), _signGrade(f._signGrade), _executeGrade(f._executeGrade) {}

Form&	Form::operator=( const Form& copy ) {
	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}


const std::string	Form::getName( void ) const {
	return (CYAN + this->_name + RESET);
}

bool				Form::getIsSigned( void ) const {
	return (this->_isSigned);
}

const size_t		Form::getSignGrade( void ) const {
	return (this->_signGrade);
}

const size_t		Form::getExecuteGrade( void ) const {
	return (this->_executeGrade);
}

std::ostream&	operator<<( std::ostream& o, Form& f ) {
	return (o << f.getName() << ", form is " << (f.getIsSigned()?"signed":"not signed") << ", the grade requirements is " << f.getSignGrade() << " to sign, and " << f.getExecuteGrade() << " to execute.");
}
