#include "head.hpp"

class Contact {
	public:
		Contact();
		~Contact();
		string	nickname;
	private:
		string	first_name;
		string	last_name;
		string	phone_number;
		string	darkest_secret;
};

Contact::Contact() {
	cout << "[New Contact]" << std::endl << std::endl;
	cout << "First name: ";
	cin >> this->first_name;
	cout << "Last name: ";
	cin >> this->last_name;
	cout << "Nickname: ";
	cin >> nickname;
	cout << "Phone number: ";
	cin >> this->phone_number;
	cout << "Tell me a darkest secret about you ('-'): ";
	cin >> this->darkest_secret;
	if (this->first_name.empty()
		|| this->last_name.empty()
		|| this->last_name.empty()
		|| this->phone_number.empty()
		|| this->darkest_secret.empty()
	)
		throw std::invalid_argument("DEU RUIM");
}

Contact::~Contact(){

}

