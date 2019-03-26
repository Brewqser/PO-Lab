#include "Player.h"

#include "txtManager.h"
#include <iostream>

namespace TG
{
	Player::Player() :_weapon("piêœæ", 1, 0), _statistics(1,1), _backpack()
	{
		
	}

	Player::Player(int hp, int bpsize)
	{
		_weapon = Weapon("piêœæ", 1, 0);
		_statistics = Statistics(hp, _weapon.getDamage());
		_backpack = Backpack(bpsize);
	}

	void Player::info()
	{
		txtManager::getTxtManager().print(this);
	}

	void Player::manage(States &s, bool &gr)
	{
		txtManager::getTxtManager().print("Player opt", 1);

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
			txtManager::getTxtManager().print("sb", 1);
			_statistics.setHp(0);
			gr = 0;
		}
	}

	void Player::useItem()
	{
		std::vector < Item > &ite = _backpack.getItems();
		
		if (ite.size() != 0)
		{
			txtManager::getTxtManager().print("Player opt2", 1);
			
			for (unsigned int i = 0; i < ite.size(); i++)
			{
				txtManager::getTxtManager().print(i+1, 1);
				ite[i].info();
			}
			txtManager::getTxtManager().print("endl", 1);

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
				txtManager::getTxtManager().print("not use item", 1);
			}
		}
		else
		{
			txtManager::getTxtManager().print("not equip wep", 1);
		}
	}

	void Player::equipWeapon()
	{
		txtManager::getTxtManager().print("Player opt3", 1);

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 0 || tmp > 2);

		if (tmp == 0)
		{
			txtManager::getTxtManager().print("undone", 1);
		}
		if (tmp == 1)
		{
			if (_weapon.getName() != "piêœæ")
			{
				_backpack.add(_weapon);
				_weapon = Weapon("piêœæ", 1, 0);
			}
			else
			{
				txtManager::getTxtManager().print("unable to can", 1);
			}
		}
		if (tmp == 2)
		{
			std::vector < Weapon > &wep = _backpack.getWeapons();
			
			if (wep.size() != 0)
			{
				txtManager::getTxtManager().print("Player opt3", 1);

				for (unsigned int i = 0; i < wep.size(); i++)
				{
					txtManager::getTxtManager().print(i+1, 1);
					wep[i].info();
				}
				txtManager::getTxtManager().print("endl", 0);

				int tmp;
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > wep.size());

				if (tmp != 0)
				{
					tmp--;
					std::swap(_weapon, wep[tmp]);
					if (wep[tmp].getName() == "piêœæ") wep.erase(wep.begin() + tmp);
				}
				else
				{
					txtManager::getTxtManager().print("swapnt", 1);
				}
			}
			else
			{
				txtManager::getTxtManager().print("weapon not", 1);
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