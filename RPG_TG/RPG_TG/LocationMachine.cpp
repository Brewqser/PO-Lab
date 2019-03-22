#include <iostream>

#include "Engine.h"
#include "LocationMachine.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Bedroom;
		_movedone = 1;
		for (int i = 0; i < amountOfLocations; i++)
		{
			_visited[i] = 0;
		}
	}

	LocationMachine::LocationMachine(const LocationMachine &)
	{

	}

	LocationMachine::~LocationMachine()
	{

	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::print()
	{
		switch (_location)
		{
		case Locations::Bedroom:
			std::cout << "Stajesz ko≥o ≥Ûøka i rozglπdasz siÍ." << std::endl;
			std::cout << "Za tobπ znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wejúcia wisi ogromne lustro" << std::endl;
			std::cout << "Twojπ uwagÍ przykuwa takøe gazeta wystajπca spod ≥Ûøka." << std::endl << std::endl;
			break;

		case Locations::Kitchen:
			std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
			std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl;
			if (_visited[Locations::Kitchen] == 0) std::cout << "Na ladzie ko≥o kuchoenki widzisz krÛtki, ale ostry nÛø" << std::endl;
			std::cout << "Przez otwarte okno wdziera sie porwisty wiatr." << std::endl << std::endl;
			
			if (_visited[Locations::Kitchen] == 0)
			{
				_visited[Locations::Kitchen] = 1;
				std::cout << "(Dodano nÛø kuchenny, pokrywka do placaka)" << std::endl << std::endl;
				Engine::getEngine().getPlayer().getBackpack().add(Weapon("Pokrywka", 2, 2));
				Engine::getEngine().getPlayer().getBackpack().add(Weapon("NÛø kuchenny", 1, 5));
			}
			break;

		case Locations::Garage:
			std::cout << "Garaø jak garaø nic tu nie ma oprÛcz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl;
			break;

		case Locations::Attic:
			std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
			std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl;
			std::cout << "Podnoszπc wie coraz wyøej spoglπdasz na stary fortepian, na ktÛrym kiedyú grywa≥eú z ojcem." << std::endl;
			if (_visited[Locations::Attic] == 0) std::cout << "Jednak przez przypadek kierujesz wzrok na inne úmieci ktÛre tam leøπ." << std::endl << std::endl;
			
			if (_visited[Locations::Attic] == 0)
			{
				_visited[Locations::Attic] = 1;
				std::cout << "(Dodano 2x stary bandaø do placaka)" << std::endl << std::endl;
				Engine::getEngine().getPlayer().getBackpack().add(Item("Staty Bandaø", 2, 6));
				Engine::getEngine().getPlayer().getBackpack().add(Item("Staty Bandaø", 3, 6));
			}
			break;

		case Locations::Basemant:
			if (_visited[Locations::Basemant] == 0)
			{
				std::cout << "Natrafiasz na 3 szczury" << std::endl;
				std::cout << "Nie moøesz uciec. " << std::endl << std::endl;
				Engine::getEngine().setState(States::fight);
				_visited[Locations::Basemant] = 1;
			}
			else
			{
				std::cout << "Pokona≥eú szczury" << std::endl;
				std::cout << "Dziwne düwiÍki nasilajπ siÍ!?" << std::endl;
				std::cout << "Z zaciekawieniem zaglπdasz do piwnicy." << std::endl;
				std::cout << "Zapalasz úwiat≥o...... " << std::endl;
				std::cout << "Wchodzisz coraz g≥Íbiej." << std::endl;
				std::cout << "Nagle wejúcie zostaje zaczaúniÍte." << std::endl;
				std::cout << "Widzisz ma≥e, s≥odki kotki i umierasz ze szczÍúcia." << std::endl;
				//std::cout << "åwiat≥o zaczyna mrÛgaÊ, widzisz tylko jakieú dziwne cienie." << std::endl;
				//std::cout << "Czujesz potÍøny, k≥ujπcy bul w klatce piersiowej." << std::endl;
				//std::cout << "Umierasz ...... " << std::endl;
				std::cout << "Happy End" << std::endl << std::endl;
				// widzsz ma≥ek kotki i umierasz ze szczÍúcia

				TG::Engine::getEngine().setGameOver();
			}
			break;

		}
	}

	void LocationMachine::locationNet()
	{
		switch (_location)
		{
		case Locations::Bedroom:
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Kitchen:
			std::cout << "1 -> Idü do sypialni" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Garage:
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do sypialni" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Attic:
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na sypialni" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Basemant:
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do sypialni" << std::endl << std::endl;
			break;

		}
	}

	void LocationMachine::move(int tmp)
	{
		switch (_location)
		{
		case Locations::Bedroom:
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			if (tmp >=1 && tmp<=4 )	_movedone = 1;
			break;

		case Locations::Kitchen:
			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			if (tmp >= 1 && tmp <= 4)	_movedone = 1;
			break;

		case Locations::Garage:
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			if (tmp >= 1 && tmp <= 4)	_movedone = 1;
			break;

		case Locations::Attic:
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
			if (tmp >= 1 && tmp <= 4)	_movedone = 1;
			break;

		case Locations::Basemant:
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Bedroom;
			if (tmp >= 1 && tmp <= 4)	_movedone = 1;
			break;

		}
	}

	bool LocationMachine::getMoveDone()
	{
		if (_movedone == 1)
		{
			return 1;
		}
		return 0;
	}

	void LocationMachine::resetMoveDone()
	{
		_movedone = 0;
	}

	void LocationMachine::setMoveDone()
	{
		_movedone = 1;
	}
}