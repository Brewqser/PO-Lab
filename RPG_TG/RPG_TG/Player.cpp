#include "Player.h"

#include <iostream>

namespace TG
{
	Player::Player() :_weapon("pi��", 1, 0), _statistics(1,1), _backpack()
	{
		
	}

	Player::Player(int hp, int bpsize)
	{
		_weapon = Weapon("pi��", 1, 0);
		_statistics = Statistics(hp, _weapon.getDamage());
		_backpack = Backpack(bpsize);
	}

	void Player::info()
	{
		_statistics.info();
		std::cout << "Bro�: ";
		_weapon.info();
		std::cout << std::endl;
	}

	void Player::manage(States &s, bool &gr)
	{
		std::cout << "Opcje: " << std::endl;
		std::cout << "1 -> plecak" << std::endl;
		std::cout << "2 -> u�yj przedmiot" << std::endl;
		std::cout << "3 -> zarz�daj broni�" << std::endl;
		std::cout << "4 -> menu poruszania" << std::endl;
		std::cout << "9 -> samob�jstwo" << std::endl;

		int tmp;
		do
		{
			std::cin >> tmp;
		} while ((tmp < 1 || tmp > 4 ) && tmp != 9 );

		if (tmp == 1)
		{
			_backpack.manage();
		}
		if (tmp == 2)
		{
			this->useItem();
		}
		if (tmp == 3)
		{
			this->equipWeapon();
		}
		if (tmp == 4)
		{
			s = States::travel;
		}
		if (tmp == 9)
		{
			std::cout << "Pope�niasz samob�jstwo" << std::endl;
			_statistics.setHp(0);
			gr = 0;
		}
	}

	void Player::useItem()
	{
		std::vector < Item > &ite = _backpack.getItems();
		
		if (ite.size() != 0)
		{
			std::cout << "Kt�rego przedmiotu chcesz u�y�: " << std::endl;
			std::cout << "0 -> �adnego" << std::endl;
			for (unsigned int i = 0; i < ite.size(); i++)
			{
				std::cout << i + 1 << " -> ";
				ite[i].info();
			}
			std::cout << std::endl;

			int tmp;
			do
			{
				std::cin >> tmp;
			} while (tmp < 0 || tmp > ite.size());

			if (tmp != 0)
			{
				tmp--;
				_statistics.updateHP(ite[tmp].getHpadd());
				ite.erase(ite.begin() + tmp);
			}
			else
			{
				std::cout << "Nie u�yto �adnego przedmiotu." << std::endl << std::endl;
			}
		}
		else
		{
			std::cout << "Nie posiadasz �adnego przedmiotu." << std::endl << std::endl;
		}
	}

	void Player::equipWeapon()
	{
		std::cout << "Co zamierzasz zrobi� z posiadan� broni�:" << std::endl;
		std::cout << "0 -> nic" << std::endl;
		std::cout << "1 -> schowaj do plecaka" << std::endl;
		std::cout << "2 -> zmie�" << std::endl;

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 0 || tmp > 2);

		if (tmp == 0)
		{
			std::cout << "Nic nie zrobiono." << std::endl << std::endl;
		}
		if (tmp == 1)
		{
			if (_weapon.getName() != "pi��")
			{
				_backpack.add(_weapon);
				_weapon = Weapon("pi��", 1, 0);
			}
			else
			{
				std::cout << "Nie mo�na zdj�� pi�ci ( xd ) " << std::endl << std::endl;
			}
		}
		if (tmp == 2)
		{
			std::vector < Weapon > &wep = _backpack.getWeapons();
			
			if (wep.size() != 0)
			{
				std::cout << "Na kt�r� bro� chcesz zamieni�:" << std::endl;
				std::cout << "0 -> �adn�" << std::endl;

				for (unsigned int i = 0; i < wep.size(); i++)
				{
					std::cout << i + 1 << " -> ";
					wep[i].info();
				}
				std::cout << std::endl;

				int tmp;
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > wep.size());

				if (tmp != 0)
				{
					tmp--;
					std::swap(_weapon, wep[tmp]);
					if (wep[tmp].getName() == "pi��") wep.erase(wep.begin() + tmp);
				}
				else
				{
					std::cout << "Nie zamieniono broni." << std::endl << std::endl;
				}
			}
			else
			{
				std::cout << "Nie posiadasz �adnej broni w plecaku." << std::endl << std::endl;
			}
		}
		_statistics.setDamage(_weapon.getDamage());
	}

	Statistics &Player::getStatistics()
	{
		return _statistics;
	}

	Backpack &Player::getBackpack()
	{
		return _backpack;
	}

	Weapon &Player::getWeapon()
	{
		return _weapon;
	}
}