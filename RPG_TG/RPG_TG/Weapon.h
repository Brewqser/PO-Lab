#pragma once

#include <string>
#include <iostream>

using namespace std;

class Weapon
{
public:
	Weapon(string name, int weight, int maxamo, int damage);

	void info();
	string getName();
	int getWeight();
	int getAmo();
	void shoot();
	void relode();

protected:
	string _name;
	int _weight;
	int _amo;
	int _maxamo;
	int _damage;
};