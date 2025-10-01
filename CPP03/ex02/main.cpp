#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");
	FragTrap f("Fraggy");

	c.attack("Scavy");
	s.takeDamage(0);
	s.attack("Fraggy");
	f.takeDamage(20);

	f.attack("Scavy");
	s.takeDamage(30);

	s.guardGate();
	f.highFivesGuys();

	FragTrap f2 = f;
	f2.attack("Clappy");

	return 0;
}