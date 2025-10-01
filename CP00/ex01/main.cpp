#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <sstream> // Agregado para stringstream

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command);

		// Detectar fin de archivo (Ctrl+D)
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting PhoneBook..." << std::endl;
			break;
		}
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			if (phoneBook.getContactCount() == 0) {
				std::cout << "No contacts to display." << std::endl;
				continue;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index to view details: ";
			std::string indexInput;
			std::getline(std::cin, indexInput);

			if (std::cin.eof()) {
				std::cout << std::endl << "Exiting PhoneBook..." << std::endl;
				break;
			}

			int index = -1;
			std::stringstream ss(indexInput);
			ss >> index;
			// Si la conversión falla o hay caracteres extra, lo trata como inválido
			if (ss.fail() || !ss.eof())
				index = -1;
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT") {
			std::cout << "Exiting PhoneBook..." << std::endl;
			break;
		}
		else if (!command.empty()) {
			std::cout << "Unknown command. Available: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return 0;
}