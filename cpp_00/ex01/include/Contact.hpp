
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

		bool	NewContact();
		void	PrintContact(size_t idx);
		void	PrintContactDetailed();
		bool	is_valid();
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	secret;
};

string	trim(const string s);
int		atoi(string s);

#endif