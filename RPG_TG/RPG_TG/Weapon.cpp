#include "Weapon.h"

Weapon::Weapon(string name, int weight, int maxamo, int damage)
{
	_name = name;
	_weight = weight;
	_maxamo = maxamo;
	_amo = maxamo;
	_damage = damage;
}

void Weapon::info()
{
	cout << _name << " " << _weight << " " << _maxamo << " " << _damage << endl;
}

string Weapon::getName()
{
	return _name;
}

int Weapon::getAmo()
{
	return _amo;
}

int Weapon::getWeight()
{
	return _weight;
}

void Weapon::shoot()
{
	if (_amo != 0)
	{
		_amo--;
	}
	else 
	{
		cout << "PUsty magazynek !? " << endl;
	}
}

void Weapon::relode()
{
	_amo = _maxamo;
}