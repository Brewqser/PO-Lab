#pragma once

#include <string>
#include <iostream>

namespace TG
{
	class Weapon
	{
	public:
		Weapon(std::string name, int weight, int damage);

		void info();

		int getWeight();
		int getDamage();
		std::string getName();

	protected:
		std::string _name;
		int _weight;
		int _damage;
	};
}