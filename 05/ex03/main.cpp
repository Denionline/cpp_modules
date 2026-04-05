
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {
	Bureaucrat	bure("Oioioioi", 5);
	AForm*		f;
	Intern		i;

	f = i.makeForm("PresidentialPardonForm", "Mibombo");
	f->beSigned(bure);
	f->execute(bure);

	delete f;
}
