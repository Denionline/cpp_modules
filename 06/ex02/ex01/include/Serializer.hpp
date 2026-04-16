#pragma once

#include "Data.h"

class Serializer {
	/* Orthodoxal Unused Functions */
	private:
		Serializer();
		Serializer( Serializer& );
		Serializer&	operator=( Serializer& copy );
		~Serializer();

	public:
		static uintptr_t	serialize( Data* );
		static Data*			deserialize( uintptr_t );
};
