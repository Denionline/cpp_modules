
#ifndef		BUREAUCRAT_H
# define	BUREAUCRAT_H

# include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		/* Orthodoxal */
		Bureaucrat();
		Bureaucrat( const std::string );
		Bureaucrat( const size_t );
		Bureaucrat( const std::string , const size_t );
		Bureaucrat( const Bureaucrat& );
		Bureaucrat&	operator=( const Bureaucrat& );
		~Bureaucrat();

		std::string	getName( void ) const;

		size_t		getGrade( void ) const;
		void		increaseGrade( void );
		void		decreaseGrade( void );

		void		signForm( AForm& );

		void		executeForm( const AForm& );

		class GradeTooHighException: public std::exception {
			public:
			const char*	what() const throw() {
				return ( BOLD RED "Grade Too High" RESET);
			}
		};

		class GradeTooLowException: public std::exception {
			public:
			const char*	what() const throw() {
				return ( BOLD RED "Grade Too Low" RESET);
			}
		};
};

std::ostream&	operator<<( std::ostream& , Bureaucrat& );

#endif