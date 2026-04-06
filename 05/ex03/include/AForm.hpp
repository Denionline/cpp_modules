#pragma once

# include <iostream>
# include <cstdlib>
# include <exception>
# include <ctime>

# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BG_DARK "\033[48;5;235m"

enum eLIMITS {
	maxGrade = 1,
	minGrade = 150
};

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const size_t		_signGrade;
		const size_t		_executeGrade;
		AForm();

	public:
		/* Orthodoxal */
		AForm( std::string );
		AForm( std::string , size_t , size_t );
		AForm( const AForm& );
		AForm&	operator=( const AForm& );
		virtual ~AForm();


		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		size_t				getSignGrade( void ) const;
		virtual size_t		getExecuteGrade( void ) const;

		void				beSigned( Bureaucrat& );
		virtual void		execute( Bureaucrat const& ) const = 0;

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
		class FailedToRobotomy: public std::exception {
			public:
				const char*	what() const throw() {
					return (BOLD YELLOW "Random number is even '-'" RESET);
				}
		};
		class FormIsNotSigned: public std::exception {
			public:
				const char*	what() const throw() {
					return (BOLD RED "Form is not signed" RESET);
				}
		};
};

std::ostream&	operator<<( std::ostream& , AForm& );
