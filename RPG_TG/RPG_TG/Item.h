#pragma once

#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	Item(string name, int weight, int hpadd);

	int gethpadd();
	int getweight();
	void info();

private:
	string _name;
	int _weight;
	int _hpadd;
};