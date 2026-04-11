#include "data.h"

Base*	generate( void ) {
	srand(time(NULL));

	size_t	opt = (rand() % 3) + 1;
	switch (opt) {
		case 1:
			return (new A);
		case 2:
			return (new B);
		case 3:
			return (new C);
		default:
			return (NULL);
	}
}

static std::string	getPointerType( Base* c ) {
	if (dynamic_cast<A*>(c))
		return ("A");
	if (dynamic_cast<B*>(c))
		return ("B");
	if (dynamic_cast<C*>(c))
		return ("C");
	return (NULL);
}

void	identify( Base* p ) {
	std::cout << "object pointed to " << getPointerType(p) << std::endl;
}

static std::string	getReferenceType( Base& c ) {
	if (dynamic_cast<A&>(c))
		return ("A");
	if (dynamic_cast<B&>(c))
		return ("B");
	if (dynamic_cast<C&>(c))
		return ("C");
	return (NULL);
}

void	identify( Base& p ) {
	std::cout << "object referenced to " << getType(p) << std::endl;
}

