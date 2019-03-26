#pragma once

#include <map>
#include <vector>
#include <string>
#include "Weapon.h"
#include "Item.h"
#include "Statistics.h"
#include "Player.h"
#include "Enemy.h"
#include "Backpack.h"

namespace TG
{

	class txtManager
	{
	public:
		static txtManager &getTxtManager();

		void print(int i, bool endl);
		void print(std::string s,bool endl);
		void print(Weapon *w);
		void print(Item *i);
		void print(Statistics *s);
		void print(Player *p);
		void print(Enemy *e);
		void print(Backpack *b);
		void attack(std::string s, int a);

		std::map < std::string, std::vector <std::string> > &getTxt();

	private:
		txtManager();
		txtManager(const txtManager &);
		~txtManager();

		std::map < std::string, std::vector <std::string> > _txt;
	};
}

