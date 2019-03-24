#pragma once

#include <string>

namespace TG
{
	class Statistics
	{
	public:
		Statistics();
		Statistics(int hp, int baseDamage,std::string name = "");

		void info();
		void updateHP(int u);
		void updateDamage(int d);

		void setName(std::string n);
		void setHp(int h);
		void setBaseDamage(int d);

		std::string getName();
		int getHp();
		int getDamage();

	private:
		std::string _name;
		int _hp;
		int _baseDamage;
		int _damage;
	};
}