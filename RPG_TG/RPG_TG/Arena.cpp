#include "Arena.h"

#include <cstdlib>
#include <iostream>

namespace TG
{
	Arena::Arena(Player &pl, int n,bool &gr)
	{
		for (int i = 0; i < n; i++)
		{
			_enemies.push_back(Enemy("Szczur", 4, rand() % 2 + 1, 3));
		}

		this->fight(pl,gr);
	}

	void Arena::fight(Player &pl,bool &gr)
	{
		while (!_enemies.empty() && pl.getStatistics().getHp() > 0 )
		{
			// tura graacza 
			std::cout << "Twoje ";
			pl.getStatistics().info();
			std::cout << "Opcje: " << std::endl;
			std::cout << "1 -> atak " << std::endl;
			std::cout << "2 -> akcje " << std::endl << std::endl;

			int tmp;
			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 2);

			if (gr)
			{
				if (tmp == 1)
				{
					for (unsigned int i = 1; i <= _enemies.size(); i++)
					{
						std::cout << i << " -> " << _enemies[i - 1].getStatistics().getName() << "\n";
						_enemies[i - 1].getStatistics().info();
					}
					std::cout << "Atakujesz: ";
					std::cin >> tmp;

					_enemies[tmp - 1].getStatistics().updateHP(-1 * pl.getStatistics().getDamage());
					if (_enemies[tmp - 1].getStatistics().getHp() <= 0) _enemies.erase(_enemies.begin() + tmp - 1);
				}
				if (tmp == 2)
				{
					States s = States::arena;
					pl.manage(s,gr);
				}
				// tura mobków

				if (gr && tmp != 2)
				{
					for (unsigned int i = 1; i <= _enemies.size(); i++)
					{
						std::cout << i << " -> " << _enemies[i - 1].getStatistics().getName() << " ";
						_enemies[i - 1].attack(pl);
					}
				}
			}
			if(gr && pl.getStatistics().getHp() > 0) std::cout << "//////////////////////////////////////////////////////////////////////" << std::endl;
		}
		
		//system("cls");
	}
}