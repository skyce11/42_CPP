#include "Harl.hpp"
#include <iostream>

int main() {
	Harl harl;

	std::cout << "Testing DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nTesting INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << "\nTesting WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nTesting ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << "\nTesting unknown level:" << std::endl;
	harl.complain("NOT_A_LEVEL");

	return 0;
}