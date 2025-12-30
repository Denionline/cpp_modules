#include "include/PhoneBook.hpp"

void	PhoneBook::AddContact () {
	Contact contact;

	contact.NewContact();
	if (this->length < 3) {
		this->contacts[this->length++] = contact;
	} else {
		this->contacts[this->oldest_idx++] = contact;
	}
}

void	PhoneBook::SearchContact() {
	cout << "|";
	cout << setw(3) << "idx" << "|";
	cout << setw(10) << "first name" << "|";
	cout << setw(10) << "last name" << "|";
	cout << setw(10) << "nickname" << "|";
	cout << std::endl;
	for (size_t i = 0; i < this->length; i++) {
		this->contacts[i].PrintContact(i);
	}
}

PhoneBook::PhoneBook() {
	this->length = 0;
	this->oldest_idx = 0;
}

PhoneBook::~PhoneBook() {
}