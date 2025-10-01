#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		--_energyPoints;
		std::cout << "ClapTrap " << _name << " attacks " << target
		          << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " can't attack (not enough energy or is dead)!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount
		          << " damage! Hit points now: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		--_energyPoints;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself for "
		          << amount << " hit points! Hit points now: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " can't repair (not enough energy or is dead)!" << std::endl;
	}
}