#pragma once

#include <iostream>
#include <string>

namespace TG
{
	class Statistics
	{
	public:
		Statistics();
		Statistics(int hp, int baseDamage);
		Statistics(std::string name,int  hp, int baseDamage);

		void info();
		void reducehp(int r);
		void addhp(int a);
		int gethp();

		void updatedamage(int u);
		int getdamage();
		std::string getname();

	private:
		std::string _name;
		int _hp;
		int _baseDamage;
		int _damage;
	};
}