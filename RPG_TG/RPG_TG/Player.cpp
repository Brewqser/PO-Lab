#include "Player.h"

namespace TG
{
	Player::Player()
	{

	}

	void Player::info()
	{
		_statistics.info();
		_backpack.info();
	}

	Backpack &Player::getBackpack()
	{
		return _backpack;
	}
}