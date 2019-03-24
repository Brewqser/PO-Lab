#pragma once

#include <string>

namespace TG
{
	class Item
	{
	public:
		Item();
		Item(std::string name, int hpadd, int weight);

		void info();

		void setName(std::string n);
		void setHpadd(int h);
		void setWeight(int w);

		std::string getName();
		int getHpadd();
		int getWeight();

	private:
		std::string _name;
		int _hpadd;
		int _weight;

	};
}