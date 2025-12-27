
#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::getline;

class Contact {
	public:
		Contact();
		~Contact();

		void	NewContact();
		void	PrintContact();
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	secret;
};

#endif