

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void	AddContact();
		void	SearchContact();
	private:
		Contact	contacts[8];
		size_t	length;
};

#endif