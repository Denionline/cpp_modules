
#ifndef		FIXED_H
# define	FIXED_H

#include <iostream>
#include <math.h>

class Fixed {
	private:
		int					_number;
		static const int	_fract = 8;
	public:
		Fixed( const Fixed& );
		Fixed( const int );
		Fixed( const float );
		Fixed();
		~Fixed();

		Fixed&	operator=( const Fixed& );
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& o, const Fixed& f );

#endif