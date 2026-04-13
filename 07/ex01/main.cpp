#include "iter.hpp"

void	toUpperString( char *&s ) {
	if (!s) return;
	for (size_t i = 0; s[i]; i++) s[i] = ::toupper(s[i]);
}

int	main( int argc , char *argv[] ) {
	(--argc, ++argv);
	if (!argc) return (1);

	::iter(argv, static_cast<size_t>(argc), toUpperString);
}
