
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm():
	_name("AForm"),
	_isSigned(false),
	_signGrade(5),
	_executeGrade(5)
{}

AForm::AForm( std::string name ):
	_name(name),
	_isSigned(false),
	_signGrade(5),
	_executeGrade(5)
{}

AForm::AForm( std::string name , size_t signGrade , size_t executeGrade ):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{}

AForm::~AForm()
{}

AForm::AForm( const AForm& f ):
	_name(f._name),
	_isSigned(f._isSigned),
	_signGrade(f._signGrade),
	_executeGrade(f._executeGrade)
{}

AForm&	AForm::operator=( const AForm& copy ) {
	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

const std::string	AForm::getName( void ) const {
	return (CYAN + this->_name + RESET);
}

bool	AForm::getIsSigned( void ) const {
	return (this->_isSigned);
}

size_t	AForm::getSignGrade( void ) const {
	return (this->_signGrade);
}

size_t	AForm::getExecuteGrade( void ) const {
	return (this->_executeGrade);
}

void	AForm::beSigned( Bureaucrat& bure ) {
	try	{
		const size_t	bureGrade = bure.getGrade();

		if (_isSigned)
			throw FormAlreadyAssigned();
		if (bureGrade > this->getSignGrade())
			throw GradeTooLowException();
		_isSigned = true;
		std::cout << bure.getName() << " signed " << this->getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr
		<< bure.getName()
		<< " couldn’t sign "
		<< getName()
		<< " because "
		<< e.what()
		<< std::endl;
	}
}

std::ostream&	operator<<( std::ostream& o, AForm& f ) {
	return (
		o
		<< f.getName()
		<< " is "
		<< ( f.getIsSigned() ? GREEN "signed" RESET : RED "not signed" RESET)
		<< ", the grade requirements are "
		<< f.getSignGrade()
		<< " to sign, and "
		<< f.getExecuteGrade()
		<< " to execute."
	);
}
