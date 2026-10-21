#include "Zombie.hpp"

int main()
{
	const int	count = 5;
	Zombie		*horde;
	int			i;

	horde = zombieHorde(count, "Horde zombie");
	if (horde == NULL)
		return (1);
	i = 0;
	while (i < count)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
}
