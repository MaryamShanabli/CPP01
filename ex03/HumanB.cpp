#include "HumanB.hpp"

#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (_weapon == NULL)
		return ;
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
