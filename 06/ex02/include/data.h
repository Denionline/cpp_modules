# ifndef	DATA_H
#  define	DATA_H

#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void );
void	identify( Base* );
void	identify( Base& );

#endif