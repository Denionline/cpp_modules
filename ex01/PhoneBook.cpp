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