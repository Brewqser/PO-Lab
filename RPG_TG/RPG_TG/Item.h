#pragma once

#include <string>
#include <iostream>

namespace TG
{
	class Item
	{
	public:
		Item(std::string name, int weight, int hpadd);

		void info();

		int gethpadd();
		int getweight();

	private:
		std::string _name;
		int _weight;
		int _hpadd;
	};
}