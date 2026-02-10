
#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::setw;

class Contact {
	public:
		Contact();
		~Contact();

		void	NewContact();
		void	PrintContact(size_t idx);
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	secret;
};

#endif