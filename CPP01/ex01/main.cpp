#include "Zombie.hpp"
#include <iostream>

// Declaración de la función externa
Zombie* zombieHorde(int N, std::string name);

int main() {
	int n = 5;
	Zombie* horde = zombieHorde(n, "HordeZombie");

	if (horde == NULL) {
		std::cout << "Invalid horde size." << std::endl;
		return 1;
	}
	for (int i = 0; i < n; ++i)
		horde[i].announce();

	delete[] horde;

	// Prueba con tamaño inválido
	Zombie* emptyHorde = zombieHorde(0, "Nobody");
	if (emptyHorde == NULL)
		std::cout << "Empty horde no creada (bien)." << std::endl;

	return 0;
}