#include "Weapon.h"

#include <iostream>

namespace TG
{

	Weapon::Weapon()
	{
		_name = "";
		_weight = 0;
		_damage = 0;
	}

	Weapon::Weapon(std::string name, int damage, int weight)
	{
		_name = name;
		_damage = damage;
		_weight = weight;
	}

	void Weapon::info()
	{
		if (_name != "")
		{
			std::cout << "nazwa: " << _name << " (obra¿enia: " << _damage << ", ciê¿ar: " << _weight << ")" <<  std::endl;
		}
		else
		{
			std::cout << "Nie posiadasz wyekwipowanej ¿adnej broni." << std::endl;
		}
	}
	
	void Weapon::setName(std::string n)
	{
		_name = n;
	}

	void Weapon::setDamage(int d)
	{
		_damage = d;
	}

	void Weapon::setWeight(int w)
	{
		_weight = w;
	}

	std::string Weapon::getName()
	{
		return _name;
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