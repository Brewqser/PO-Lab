#include "Player.h"



Player::Player() :_wp("Digle", 1 ,2, 50)
{

}

void Player::takeDamage(int d)
{
	_stats.hpminus(d);
}

void Player::lvlup()
{
	_stats.lvlup();
}

void Player::changeWeapon( int w)
{
	swap(_wp, _bp._weapons[w]);
}

void Player::dealDamage()
{

}