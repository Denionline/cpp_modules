
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {
	{
		Bureaucrat				bure("Minino", 146);
		ShrubberyCreationForm	shru;

		std::cout << shru << std::endl;

		std::cout << bure << std::endl;
		bure.decreaseGrade();
		std::cout << bure << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
		shru.beSigned(bure);
		bure.increaseGrade();
		shru.beSigned(bure);
		std::cout << bure << std::endl;
		shru.beSigned(bure);
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		bure.increaseGrade();
		shru.execute(bure);
	}
	{
		Bureaucrat			bure("Cabra", 46);
		RobotomyRequestForm	robo;

		std::cout << robo << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
		robo.execute(bure);
	}
	{
		Bureaucrat				bure("Cabra", 5);
		PresidentialPardonForm	presi;

		presi.beSigned(bure);
		presi.execute(bure);
	}
	{
		ShrubberyCreationForm	s;
		RobotomyRequestForm		r;
		PresidentialPardonForm	p;
		Bureaucrat				bure("Cabra", 5);

		bure.signForm(s);
		bure.executeForm(s);
		bure.signForm(r);
		bure.executeForm(r);
		bure.signForm(p);
		bure.executeForm(p);
	}
}
