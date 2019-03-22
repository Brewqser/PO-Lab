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
		if (_name != "brak")
		{
			std::cout << "Broñ: " << _name << " " << _weight << " " << _damage << std::endl;
		}
		else
		{
			std::cout << "Broñ: " << _name << std::endl;
		}
	}

	int Weapon::getDamage()
	{
		return _damage;
	}

	int Weapon::getWeight()
	{
		return _weight;
	}

	std::string Weapon::getName()
	{
		return _name;
	}
}