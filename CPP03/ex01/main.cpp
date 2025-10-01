#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap st("Serena");
	ClapTrap ct("Clappy");

	st.attack("Clappy");
	ct.takeDamage(20);

	st.guardGate();

	ScavTrap st2 = st;
	st2.attack("Serena");

	return 0;
}