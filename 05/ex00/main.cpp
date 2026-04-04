
#include "Bureaucrat.hpp"

int	main( void ) {
	{
		Bureaucrat	bure;

		std::cout << bure << std::endl;

		bure.increaseGrade();

		for (int i = bure.getGrade(); i < minGrade; i++) {
			bure.decreaseGrade();
		}

		std::cout << bure << std::endl;

		bure.decreaseGrade();
	}
}
