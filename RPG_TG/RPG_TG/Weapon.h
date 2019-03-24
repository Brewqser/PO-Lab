#pragma once

#include <string>

namespace TG
{
	class Weapon
	{
	public:
		Weapon();
		Weapon(std::string name, int damage, int weight);

		void info();

		void setName(std::string n);
		void setDamage(int d);
		void setWeight(int w);

		std::string getName();
		int getDamage();
		int getWeight();

	protected:
		std::string _name;
		int _damage;
		int _weight;

	};
}