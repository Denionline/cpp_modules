#include "include/PhoneBook.hpp"

void	PhoneBook::AddContact () {
	Contact contact;

	contact.NewContact();
	this->contacts[this->length] = contact;
	this->length += 1;
}

void	PhoneBook::SearchContact() {
	for (size_t i = 0; i < this->length; i++) {
		this->contacts[i].PrintContact();
	}
}

PhoneBook::PhoneBook() {
	this->length = 0;
}

PhoneBook::~PhoneBook() {
}