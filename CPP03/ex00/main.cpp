#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Skyce");
	ClapTrap b("Madirex");

	a.attack("Madirex");
	b.takeDamage(0);

	b.attack("Skyce");
	a.takeDamage(0);

	a.beRepaired(5);
	b.beRepaired(3);

	return 0;
}