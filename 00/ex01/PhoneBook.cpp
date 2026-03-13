/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:46:15 by dximenes          #+#    #+#             */
/*   Updated: 2026/03/13 18:46:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	PhoneBook::AddContact () {
	static size_t	oldest_idx;
	Contact			contact;

	if (!contact.NewContact()) {
		return (false);
	}
	if (this->length == 0 || oldest_idx >= 8)
		oldest_idx = 0;
	if (this->length < 8) {
		this->contacts[this->length++] = contact;
	} else {
		this->contacts[oldest_idx++] = contact;
	}
	return (true);
}

bool	PhoneBook::SearchContact() {
	ShowContactList();
	while (true) {
		std::string	idx_string;

		std::cout << "Insert a index [0-7] (To exit type: exit): ";
		if (!std::getline(std::cin, idx_string)) return (false);
		if (idx_string == "exit") return (true);
		if (!isNumber(idx_string)) {
			std::cout << "Only numbers allowed!" << std::endl;
			continue;
		}
		int	idx = std::strtol(idx_string.c_str(), NULL, 10);
		if (idx < 0 || idx > 7 || idx_string.size() > 1) {
			std::cout << "Invalid index range between 0 and 7" << std::endl;
			continue;
		}
		Contact chosen = this->contacts[idx];
	
		if (chosen.is_valid()) {
			chosen.PrintContactDetailed();
		} else {
			std::cout << "Not found a contact with this index" << std::endl;
		}
	}
	return (true);
}

bool	PhoneBook::ShowContactList() {
	std::cout << "|";
	std::cout << std::setw(3) << "idx" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
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