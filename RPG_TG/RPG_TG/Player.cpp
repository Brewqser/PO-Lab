#include "Player.h"

#include <iostream>

namespace TG
{
	Player::Player() : _weapon("brak", 0, 0)
	{
		
	}

	void Player::info()
	{
		_statistics.info();
		_weapon.info();
		std::cout << std::endl;
		_backpack.info();
	}

	Backpack &Player::getBackpack()
	{
		return _backpack;
	}

	void Player::useItem()
	{
		if (!_backpack.getItems().empty())
		{
			std::cout << "0 -> powrót" << std::endl;

			_backpack.showItems();
			int a;
			std::cin >> a;
			if (a > 0 && a <= _backpack.getItems().size())
			{
				_statistics.addhp( _backpack.getItems()[a - 1].gethpadd() );
				_backpack.remove(a - 1, 'i');
			}
		}
		else
		{
			std::cout << "Nie posiadasz ¿adnych przedmiotów" << std::endl;
		}
	}

	void Player::updateWeapon()
	{
		if (!_backpack.getWeapons().empty())
		{
			std::cout << "-1 -> zdejmi broñ" << std::endl;
			std::cout << "0 -> powrót" << std::endl;

			_backpack.showWeapons();
			int a;
			std::cin >> a;
			if (a > 0 && a <= _backpack.getWeapons().size())
			{
				if (_weapon.getName() == "brak")
				{
					_weapon = _backpack.getWeapons()[a - 1];
					_backpack.remove(a - 1, 'w');
				}
				else
				{
					std::swap(_weapon, _backpack.getWeapons()[a - 1]);
				}
			}

			if (a == -1)
			{
				if (_weapon.getName() != "brak")
				{
					_backpack.add(_weapon);
					_weapon = Weapon("brak", 0, 0);
				}
				else
				{
					std::cout << "Nie masz za³o¿onej ¿adnej broni" << std::endl;
				}
			}

			_statistics.updatedamage(_weapon.getDamage());
		}
		else
		{
			std::cout << "Nie posiadasz ¿adnych dodatkowych broni" << std::endl;
		}
	}
}