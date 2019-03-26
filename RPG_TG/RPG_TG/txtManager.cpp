#include "txtManager.h"

#include <iostream>

namespace TG
{
	txtManager &txtManager::getTxtManager()
	{
		static txtManager texts;
		return texts;
	}

	void txtManager::print(int i, bool endl)
	{
		std::cout << i;
		this->print("arrow", endl);
	}

	void txtManager::print(std::string s, bool endl)
	{
		for (int i = 0; i < _txt[s].size(); i++)
		{
			std::cout << _txt[s][i];
			if (endl)
			{
				std::cout << std::endl;
			}
		}
	}

	void txtManager::print(Weapon *w)
	{
		if ( w->getName() != "")
		{
			std::cout << w->getName();
			this->print(" ", 0);
			this->print("(",0);
			this->print("obrazenia",0);
			this->print(":",0);
			this->print(" ", 0);
			std::cout << w->getDamage();
			this->print(",",0);
			this->print(" ", 0);
			this->print("ciezar",0);
			this->print(":",0);
			this->print(" ", 0);
			std::cout << w->getWeight();
			this->print(")",1);
		}
		else
		{
			this->print("Brak broni",1);
		}
	}

	void txtManager::print(Item *i)
	{
		if (i->getName() != "")
		{
			std::cout << i->getName();
			this->print(" ", 0);
			this->print("(",0);
			this->print("leczenie",0);
			this->print(":",0);
			this->print(" ", 0);
			std::cout << i->getHpadd();
			this->print(",",0);
			this->print(" ", 0);
			this->print("ciezar",0);
			this->print(":",0);
			this->print(" ", 0);
			std::cout << i->getWeight();
			this->print(")",1);
		}
		else
		{
			this->print("Brak przedmiotu",1);
		}
	}

	void txtManager::print(Statistics *s)
	{
		this->print("Statystyki", 0);
		this->print(":", 1);
		this->print("-", 0);
		this->print(" ", 0);
		this->print("HP", 0);
		this->print(":", 0);
		this->print(" ", 0);
		std::cout << s->getHp();
		this->print("endl", 0);
		this->print("-", 0);
		this->print(" ", 0);
		this->print("Damage", 0);
		this->print(":", 0);
		this->print(" ", 0);
		std::cout << s->getDamage();
		this->print("endl", 0);

	}

	void txtManager::print(Player *p)
	{
		this->print(&p->getStatistics());
		this->print("endl", 0);
		this->print("Bron",0);
		this->print(":", 0);
		this->print(" ", 0);
		this->print(&p->getWeapon());
		this->print("endl", 0);
	}

	txtManager::txtManager()
	{
		setlocale(LC_ALL, "");
		std::string key;

		key = "weapon not";
		_txt[key].push_back("Nie posiadasz ¿adnej broni w plecaku.");

		key = "swapnt";
		_txt[key].push_back("Nie zamieniono broni.");

		key = "arrow";
		_txt[key].push_back(" -> ");

		key = "Player opt3";
		_txt[key].push_back("Na któr¹ broñ chcesz zamieniæ:");
		_txt[key].push_back("0 -> ¿adnego");

		key = "unable to can";
		_txt[key].push_back("Nie mo¿na.");

		key = "undone";
		_txt[key].push_back("Nic nie zrobiono.");

		key = "Player opt";
		_txt[key].push_back("Co zamierzasz zrobiæ z posiadan¹ broni¹:");
		_txt[key].push_back("0 -> nic");
		_txt[key].push_back("1 -> schowaj do plecaka");
		_txt[key].push_back("2 -> zmieñ");

		key = "not use item";
		_txt[key].push_back("Nie u¿yto ¿adnego przedmiotu.");

		key = "not equip wep";
		_txt[key].push_back("Nie posiadasz ¿adnego przedmiotu.");

		key = "Player opt2";
		_txt[key].push_back("Którego przedmiotu chcesz u¿yæ:");
		_txt[key].push_back("0 -> ¿adnego");

		key = "sb";
		_txt[key].push_back("Pope³niasz samobójstwo.");

		key = "Player opt";
		_txt[key].push_back("Opcje:");
		_txt[key].push_back("1 -> plecak");
		_txt[key].push_back("2 -> u¿yj przedmiot");
		_txt[key].push_back("3 -> zarz¹daj broni¹");
		_txt[key].push_back("4 -> menu poruszania");
		_txt[key].push_back("9 -> samobójstwo");

		key = "Bron";
		_txt[key].push_back("Bron");

		key = " ";
		_txt[key].push_back(" ");

		key = "endl";
		_txt[key].push_back("\n");

		key = "HP";
		_txt[key].push_back("HP");

		key = "Damage";
		_txt[key].push_back("Damage");

		key = "Statystyki";
		_txt[key].push_back("Statystyki");

		key = "Brak broni";
		_txt[key].push_back("Brak broni.");

		key = "Brak przedmiotu";
		_txt[key].push_back("Brak przedmiotu.");

		key = "-";
		_txt[key].push_back("-");

		key = "(";
		_txt[key].push_back("(");

		key = ")";
		_txt[key].push_back(")");

		key = ":";
		_txt[key].push_back(":");

		key = ",";
		_txt[key].push_back(",");

		key = "obrazenia";
		_txt[key].push_back("obrazenia");

		key = "leczenie";
		_txt[key].push_back("leczenie");

		key = "ciezar";
		_txt[key].push_back("ciezar");

		//key = "Brak broni";
		//_txt[key].push_back("Brak broni.");
	}

	std::map < std::string, std::vector <std::string> > &txtManager::getTxt()
	{
		return _txt;
	}

	txtManager::txtManager(const txtManager &)
	{

	}

	txtManager::~txtManager()
	{

	}

}