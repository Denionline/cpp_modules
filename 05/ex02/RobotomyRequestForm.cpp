
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyForm", 72, 45),
	_target("Robotomy")
{}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& f ):
	AForm(f.getName(), f.getSignGrade(), f.getExecuteGrade()),
	_target(f._target)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy ) {
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


std::string	RobotomyRequestForm::getTarget( void ) const {
	return (CYAN + this->_target + RESET);
}

void	RobotomyRequestForm::execute( const Bureaucrat& b ) const{
	try {
		if (!getIsSigned())
			throw AForm::FormIsNotSigned();
		if (b.getGrade() > this->getExecuteGrade())
			throw AForm::GradeTooLowException();
		std::srand(std::time(NULL));
		if (std::rand() % 2)
			throw AForm::FailedToRobotomy();
		system("paplay /usr/share/sounds/freedesktop/stereo/suspend-error.oga");

		std::cout
		<< b.getName()
		<< " executed "
		<< getName()
		<< std::endl;
	}
	catch ( std::exception& e ) {
		std::cerr << "Robotomy failed because " << e.what() << std::endl;
	}
}