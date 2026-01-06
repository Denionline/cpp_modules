#include "include/Contact.hpp"

static string	prompt(string label) {
	while (true) {
		string	result;
		cout << label;
		getline(cin, result);
		if (!result.empty()) {
			return (result);
		}
		cout << "Please fill the field to continue..." << std::endl;
	}
}

void	Contact::NewContact() {
	this->first_name = prompt("First name: ");
	this->last_name = prompt("Last name: ");
	this->nickname = prompt("Nickname: ");
	this->phone_number = prompt("Phone number: ");
	this->secret = prompt("Tell me a darkest secret about you ('-'): ");
}

static string formatColumn(const string &str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::PrintContact(size_t idx) {
	cout << "|";
	cout << setw(3) << idx << "|";
	cout << setw(10) << formatColumn(this->first_name) << "|";
	cout << setw(10) << formatColumn(this->last_name) << "|";
	cout << setw(10) << formatColumn(this->nickname) << "|";
	cout << std::endl;;
}

Contact::Contact() {
}

Contact::~Contact(){

}