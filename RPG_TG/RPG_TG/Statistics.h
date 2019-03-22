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

		int gethp();

	private:
		int _hp;
		int _baseDamage;
	};
}