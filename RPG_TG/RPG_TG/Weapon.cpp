#include "Weapon.h"

namespace TG
{
	Weapon::Weapon(std::string name, int weight, int damage)
	{
		_name = name;
		_weight = weight;
		_damage = damage;
	}

	void Weapon::info()
	{
		std::cout << _name << " " << _weight << " " << _damage << std::endl;
	}

	int Weapon::getDamage()
	{
		return _damage;
	}

	int Weapon::getWeight()
	{
		return _weight;
	}
}