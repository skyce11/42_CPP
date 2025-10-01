#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		contactCount;
	int		oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void displayContacts() const;
	void displayContact(int index) const;
	int  getContactCount() const;
};

#endif