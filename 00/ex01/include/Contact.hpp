
#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact {
	public:
		Contact();
		~Contact();

		bool	NewContact();
		void		PrintContactDetailed();
		bool		is_valid();
		void		PrintContact(size_t idx);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

};

std::string	trim(const std::string s);
bool		isNumber(std::string str);

#endif