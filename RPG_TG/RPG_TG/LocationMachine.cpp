#include <iostream>

#include "Engine.h"
#include "LocationMachine.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Bedroom;
	}

	LocationMachine::LocationMachine(const LocationMachine &)
	{

	}

	LocationMachine::~LocationMachine()
	{

	}

	auto LocationMachine::getLocation()
	{
		return _location;
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::print()
	{
		if (_location == Locations::Bedroom)
		{
			std::cout << "Stajesz ko≥o ≥Ûøka i rozglπdasz siÍ." << std::endl;
			std::cout << "Za tobπ znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wejúcia wisi ogromne lustro" << std::endl;
			std::cout << "Twojπ uwagÍ przykuwa takøe gazeta wystajπca spod ≥Ûøka." << std::endl << std::endl;
		}
		if (_location == Locations::Kitchen)
		{
			std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
			std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl;
			std::cout << "Na ladzie ko≥o kuchoenki widzisz krÛtki, ale ostry nÛø" << std::endl;
			std::cout << "Przez otwarte okno wdziera sie porwisty wiatr." << std::endl << std::endl;
		}
		if (_location == Locations::Garage)
		{
			std::cout << "Garaø jak garaø nic tu nie ma oprÛcz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl;
		}
		if (_location == Locations::Attic)
		{
			std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
			std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl;
			std::cout << "Podnoszπc wie coraz wyøej spoglπdasz na stary fortepian, na ktÛrym kiedyú grywa≥eú z ojcem." << std::endl;
			std::cout << "Jednak przez przypadek kierujesz wzrok na inne úmieci ktÛre tam leøπ." << std::endl << std::endl;
		}
		if (_location == Locations::Basemant)
		{
			std::cout << "Dziwne düwiÍki nasilajπ siÍ!?" << std::endl;
			std::cout << "Z zaciekawieniem zaglπdasz do piwnicy." << std::endl;
			std::cout << "Zapalasz úwiat≥o...... " << std::endl;
			std::cout << "Wchodzisz coraz g≥Íbiej" << std::endl;
			std::cout << "Nagle wejúcie zostaje zaczaúniÍte" << std::endl;
			std::cout << "åwiat≥o zaczyna mrÛgaÊ, widzisz tylko jakieú dziwne cienie." << std::endl;
			std::cout << "Czujesz potÍøny, k≥ujπcy bul w klatce piersiowej." << std::endl;
			std::cout << "Umierasz ...... " << std::endl;
			std::cout << "GAME OVER" << std::endl << std::endl;

			TG::Engine::getEngine().setGameOver();
		}
	
	}

	void LocationMachine::LocationNet()
	{
		int tmp;
		if (_location == Locations::Bedroom)
		{
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Kitchen)
		{
			std::cout << "1 -> Idü do sypialni" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Garage)
		{
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do sypialni" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
			
			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Attic)
		{
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na sypialni" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Basemant)
		{
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do sypialni" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Bedroom;
		}

	}
}