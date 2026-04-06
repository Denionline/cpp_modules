#pragma once

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const size_t		_signGrade;
		const size_t		_executeGrade;

	public:
		/* Orthodoxal */
		Form();
		Form( const std::string );
		Form( const Form& );
		Form&	operator=( const Form& );
		~Form();

		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		size_t				getSignGrade( void ) const;
		size_t				getExecuteGrade( void ) const;

		void				beSigned( Bureaucrat& );

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw() {
					return ( BOLD RED "Grade Too High" RESET);
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw() {
					return ( BOLD RED "Grade Too Low" RESET);
				}
		};
		class FormAlreadyAssigned: public std::exception {
			public:
				const char* what() const throw() {
					return ( BOLD RED "Form is already assigned" RESET);
				}
		};
};

std::ostream&	operator<<( std::ostream& , Form& );
