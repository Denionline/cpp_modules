
#ifndef		FIXED_H
# define	FIXED_H

#include <iostream>

class Fixed {
	private:
		int					_number;
		static const int	_fract = 8;
	public:
		Fixed();
		Fixed( Fixed& );
		~Fixed();

		Fixed&	operator=( const Fixed& );
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
};

#endif