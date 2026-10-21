#include "Zombie.hpp"

int main()
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Heap zombie");
	heapZombie->announce();
	randomChump("Stack zombie");
	delete heapZombie;
	return 0;
}
