#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		--_energyPoints;
		std::cout << "FragTrap " << _name << " attacks " << target
		          << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << _name << " can't attack (not enough energy or is dead)!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}