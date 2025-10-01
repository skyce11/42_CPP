#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}