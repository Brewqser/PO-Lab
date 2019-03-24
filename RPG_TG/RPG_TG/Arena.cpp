#include "Arena.h"

#include <cstdlib>
#include <iostream>

namespace TG
{
	Arena::Arena(Player &pl, int n)
	{

		for (int i = 0; i < n; i++)
		{
			_enemies.push_back(Enemy("Szczur", 4, rand() % 2 + 1, 3));
		}

		this->fight(pl);
	}

	void Arena::fight(Player &pl)
	{
		int tmp;
		system("cls");

		while (!_enemies.empty() && pl.getStatistics().getHp() > 0 )
		{
			// tura graacza 
			for (unsigned int i = 1; i <= _enemies.size(); i++)
			{
				std::cout << i << " -> " << _enemies[i - 1].getStatistics().getName() << " ";
				_enemies[i - 1].getStatistics().info();
			}

			pl.getStatistics().info();
			std::cout << "Atakujesz: ";

			std::cin >> tmp;
			
			_enemies[tmp - 1].getStatistics().updateHP(-1 * pl.getStatistics().getDamage());
			if ( _enemies[tmp - 1].getStatistics().getHp() <= 0 ) _enemies.erase(_enemies.begin() + tmp - 1);

			// tura mobk�w

			for (unsigned int i = 1; i <= _enemies.size(); i++)
			{
				std::cout << i << " -> " << _enemies[i - 1].getStatistics().getName() << " ";
				_enemies[i - 1].attack(pl);
			}
			std::cout << std::endl;
		}
		system("cls");
	}
}