
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void ) {
	{
		Form		form("Formulario");
		Bureaucrat	bure("BureBure", 5);

		bure.getGrade();
		std::cout << bure << std::endl;
		bure.signForm(form);
		std::cout << form << std::endl;
	}
}
