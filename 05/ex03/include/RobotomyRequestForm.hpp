#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string	_target;

	public:
		/* Orthodoxal */
		RobotomyRequestForm();
		RobotomyRequestForm( const std::string );
		RobotomyRequestForm( const RobotomyRequestForm& );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& );
		~RobotomyRequestForm();

		std::string	getTarget( void ) const;

		void		execute( Bureaucrat const& ) const;
};
