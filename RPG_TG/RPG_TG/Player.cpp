#include "Player.h"

#include <iostream>

namespace TG
{
	Player::Player() : _weapon()
	{
		
	}

	void Player::info()
	{
		_statistics.info();
		std::cout << "Wyekwipowana Broñ -> ";
		_weapon.info();
		std::cout << std::endl;
		_backpack.info();
	}

	void Player::opcions()
	{
		std::cout << "Opcje: " << std::endl;
		std::cout << "0 -> powrót" << std::endl;
		std::cout << "p -> zarz¹dzaj polecakiem" << std::endl;
		std::cout << "b -> zarz¹dzaj trzyman¹ broni¹" << std::endl << std::endl;
	}

	void Player::manage(char a)
	{
		if (a == 'p') _backpack.manage();
		if (a == 'b') this->equipWeapon();
	}

	void Player::equipWeapon()
	{
		std::cout << "Wyekwipowana Broñ -> ";
		_weapon.info();
		std::cout << std::endl;

		std::vector < Weapon > &wep = _backpack.getWeapons();

		std::cout << "Broneie w plaecaku: " << std::endl;
		std::cout << "0 -> powrót" << std::endl;
		std::cout << "1 -> zdejmij" << std::endl;
		for (unsigned int i = 0; i < wep.size(); i++)
		{
			std::cout << i + 2 << " -> ";
			wep[i].info();
		}
		int a;

		std::cout << wep.size() << std::endl;
		do
		{
			std::cin >> a;
		} while (a < 0 || a > (int)wep.size() + 1);

		if (a != 0)
		{
			if (_weapon.getName() == "")
			{
				if (a != 1)
				{
					_weapon = wep[a - 2];
					wep.erase(wep.begin() + (a - 2));
				}
				else
				{
					std::cout << "Nie masz za³o¿onej broni" << std::endl << std::endl;
				}
			}
			else
			{
				if (a == 1)
				{
					wep.push_back(_weapon);
					_weapon = Weapon();
				}
				else
				{
					std::swap(_weapon, wep[a - 2]);
				}
			}
			//std::cout << wep.size() << std::endl;
		}
	
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