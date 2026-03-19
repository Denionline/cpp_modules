
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

		void				setRawBits( int const raw );
		int					getRawBits( void ) const;
		float				toFloat( void ) const;
		int					toInt( void ) const;

		Fixed&				operator=( const Fixed& );
		bool				operator>( const Fixed& ) const;
		bool				operator>=(const  Fixed& ) const;
		bool				operator<( const Fixed& ) const;
		bool				operator<=(const  Fixed& ) const;
		bool				operator==(const  Fixed& ) const;
		bool				operator!=(const  Fixed& ) const;
		Fixed				operator+( const Fixed& );
		Fixed				operator-( const Fixed& );
		Fixed				operator*( const Fixed& );
		Fixed				operator/( const Fixed& );
		Fixed&				operator++( void );
		Fixed				operator++( int );
		Fixed&				operator--( void );
		Fixed				operator--( int );
		static Fixed&		max( Fixed& , Fixed& );
		static Fixed&		min( Fixed& , Fixed& );
		static const Fixed&	max( const Fixed& , const Fixed& );
		static const Fixed&	min( const Fixed& , const Fixed& );
};

std::ostream&	operator<<( std::ostream& o, const Fixed& f );

#endif