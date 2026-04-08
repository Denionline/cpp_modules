#pragma once

#include "Data.h"

class Serializer {
	public:
		virtual ~Serializer() = 0;
		static uintptr_t	serialize( Data* );
		static Data* 		deserialize( uintptr_t );
};
