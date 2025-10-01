#include "Zombie.hpp"

// Forward declarations
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	// Prueba 1: Zombie en heap
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie; // Se debe ver el mensaje del destructor

	// Prueba 2: Zombie en stack
	randomChump("StackZombie"); // Se destruye automáticamente al salir de la función

	// Prueba 3: Varios zombies en heap y stack
	Zombie* alice = newZombie("Alice");
	Zombie* bob = newZombie("Bob");
	alice->announce();
	bob->announce();
	delete alice;
	delete bob;

	randomChump("Charlie");
	randomChump("Diana");

	return 0;
}