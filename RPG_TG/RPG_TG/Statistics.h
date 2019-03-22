#pragma once

#include <iostream>

namespace TG
{
	class Statistics
	{
	public:
		Statistics();
		Statistics(int hp, int baseDamage);

		void info();
		void reducehp(int r);
		void addhp(int a);
		int gethp();

		void updatedamage(int u);
		int getdamage();

	private:
		int _hp;
		int _baseDamage;
		int _damage;
	};
}