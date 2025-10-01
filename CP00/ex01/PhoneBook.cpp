#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "First name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Last name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Nickname cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Phone number cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Darkest secret cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	newContact.setDarkestSecret(input);

	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	} else {
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added!" << std::endl;
}

static std::string formatField(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; ++i) {
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << formatField(contacts[i].getLastName()) << "|"
			<< std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	const Contact& c = contacts[index];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const {
	return contactCount;
}