
#ifndef CONTACT_H
# define CONTACT_H

#include "head.hpp"

class Contact {
	public:
		Contact();
		~Contact();

		void	NewContact(); 
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	secret;
};

#endif