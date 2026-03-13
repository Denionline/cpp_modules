#include "include/PhoneBook.hpp"

bool	PhoneBook::AddContact () {
	static size_t	oldest_idx;
	Contact			contact;

	if (!contact.NewContact()) {
		// contact.~Contact();
		return (false);
	}
	if (this->length == 0 || oldest_idx >= 3)
		oldest_idx = 0;
	if (this->length < 3) {
		this->contacts[this->length++] = contact;
	} else {
		this->contacts[oldest_idx++] = contact;
	}
	return (true);
}

bool	PhoneBook::SearchContact() {
	ShowContactList();
	while (true) {
		string	idx_string;
		int		idx;
		
		cout << "Insert a index [0-7]:";
		if (!getline(cin, idx_string)) return (false);
		idx = atoi(idx_string);
		if (idx < 0 || idx > 7) {
			cout << "Invalid index range between 0 and 7" << std::endl;
			continue;
		}
		Contact chosen = this->contacts[idx];
	
		if (chosen.is_valid()) {
			chosen.PrintContactDetailed();
		} else {
			cout << "Not found a contact with this index" << std::endl;
		}
	}
	return (true);
}

bool	PhoneBook::ShowContactList() {
	cout << "|";
	cout << setw(3) << "idx" << "|";
	cout << setw(10) << "first name" << "|";
	cout << setw(10) << "last name" << "|";
	cout << setw(10) << "nickname" << "|";
	cout << std::endl;
	for (size_t i = 0; i < this->length; i++) {
		this->contacts[i].PrintContact(i);
	}
	return (true);
}

PhoneBook::PhoneBook() {
	this->length = 0;
}

PhoneBook::~PhoneBook() {
}