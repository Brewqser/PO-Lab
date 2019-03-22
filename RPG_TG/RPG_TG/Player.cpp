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

		std::cout << "Opcje: " << std::endl;
		std::cout << "i -> zarz�dzaj przedmiotami " << std::endl;
		std::cout << "w -> zarz�dzaj bro�mi " << std::endl;
		std::cout << "r -> usu� co� z zawarto�ci placaka" << std::endl << std::endl;
	}

	Backpack &Player::getBackpack()
	{
		return _backpack;
	}

	void Player::useItem()
	{
		if (!_backpack.getItems().empty())
		{
			std::cout << "0 -> powr�t" << std::endl;

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
			std::cout << "Nie posiadasz �adnych przedmiot�w" << std::endl;
		}
	}

	void Player::updateWeapon()
	{
		if (!_backpack.getWeapons().empty())
		{
			std::cout << "-1 -> zdejmi bro�" << std::endl;
			std::cout << "0 -> powr�t" << std::endl;

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
					std::cout << "Nie masz za�o�onej �adnej broni" << std::endl;
				}
			}

			_statistics.updatedamage(_weapon.getDamage());
		}
		else
		{
			std::cout << "Nie posiadasz �adnych dodatkowych broni" << std::endl;
		}
	}

	void Player::removeItem()
	{
		std::cout << "Co chcesz usun��:" << std::endl;
		std::cout << "i -> przedmiot " << std::endl;
		std::cout << "w -> bro� " << std::endl;

		char a;
		std::cin >> a;

		std::cout << "0 -> powr�t" << std::endl;

		if (a == 'i')
		{
			_backpack.showItems();

			int b;
			std::cin >> b;

			if (b > 0 && b <= _backpack.getItems().size())
			{
				_backpack.remove(b - 1, 'i');
			}
		}
		else if (a == 'w')
		{
			_backpack.showWeapons();

			int b;
			std::cin >> b;

			if (b > 0 && b <= _backpack.getWeapons().size())
			{
				_backpack.remove(b - 1, 'w');
			}
		}
	}

	int Player::gethp()
	{
		return _statistics.gethp();
	}

	Statistics &Player::getStatistics()
	{
		return _statistics;
	}

	Weapon &Player::getWeapon()
	{
		return _weapon;
	}
}