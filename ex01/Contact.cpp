#include "include/Contact.hpp"

static void	prompt(string label, string variable) {
	while (variable.empty()) {
		cout << label;
		getline(cin, variable);
		if (variable.empty()) {
			cout << "Please fill the field to continue..." << std::endl;
		}
	}
}

void	Contact::NewContact() {
	prompt("First name: ", this->first_name);
	prompt("Last name: ", this->last_name);
	prompt("Nickname: ", this->nickname);
	prompt("Phone number: ", this->phone_number);
	prompt("Tell me a darkest secret about you ('-'): ", this->secret);
}

Contact::Contact() {
}

Contact::~Contact(){

}