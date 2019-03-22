#include "Arena.h"

namespace TG
{
	Arena::Arena()
	{

	}

	Arena::Arena(int n)
	{
		for (int i = 0; i < n; i++)
		{
			_enemies.push_back(Enemy("Szczur", 4, 2));
		}

		this->fight();
	}

	void Arena::fight()
	{

		int tmp;

		while (!_enemies.empty() && Engine::getEngine().getPlayer().getStatistics().gethp() > 0 )
		{
			// tura graacza 
			for (unsigned int i = 1; i <= _enemies.size(); i++)
			{
				std::cout << i << " -> " << _enemies[i - 1].getStatistics().getname() << " ";
				_enemies[i - 1].getStatistics().info();
			}

			Engine::getEngine().getPlayer().getStatistics().info();

			std::cout << std::endl;
			std::cout << "Atakujesz: ";

			std::cin >> tmp;
			
			_enemies[tmp - 1].getStatistics().reducehp(Engine::getEngine().getPlayer().getStatistics().getdamage());
			if (_enemies[tmp - 1].getStatistics().gethp() <= 0) _enemies.erase(_enemies.begin() + tmp - 1);

			// tura mobków
			for (unsigned int i = 1; i <= _enemies.size(); i++)
			{
				std::cout << i << " -> " << _enemies[i - 1].getStatistics().getname() << " ";
				_enemies[i - 1].attac();
			}
			std::cout << std::endl;
		}
	}
}