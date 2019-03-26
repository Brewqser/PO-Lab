#include "Arena.h"

#include <cstdlib>
#include <iostream>
#include "txtManager.h"

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
			txtManager::getTxtManager().print("twoje", 1);
			txtManager::getTxtManager().print(&pl.getStatistics());
			txtManager::getTxtManager().print("Arena opt", 1);

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
						txtManager::getTxtManager().print( i , 0);
						txtManager::getTxtManager().print(&_enemies[i-1]);
					}
					txtManager::getTxtManager().print("patt", 1);
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
						txtManager::getTxtManager().print(i, 0);

						txtManager::getTxtManager().print(_enemies[i - 1].getStatistics().getName(), 0);
						txtManager::getTxtManager().print(" ", 0);
						_enemies[i - 1].attack(pl);
					}
				}
			}
			if(gr && pl.getStatistics().getHp() > 0) txtManager::getTxtManager().print("///", 1);
		}
		
		//system("cls");
	}
}