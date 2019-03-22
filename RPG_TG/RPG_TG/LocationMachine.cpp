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
			std::cout << "Stajesz ko�o ��ka i rozgl�dasz si�." << std::endl;
			std::cout << "Za tob� znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wej�cia wisi ogromne lustro" << std::endl;
			std::cout << "Twoj� uwag� przykuwa tak�e gazeta wystaj�ca spod ��ka." << std::endl << std::endl;
			break;

		case Locations::Kitchen:
			std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
			std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
			if (_visited[Locations::Kitchen] == 0) std::cout << "Na ladzie ko�o kuchoenki widzisz kr�tki, ale ostry n�" << std::endl;
			std::cout << "Przez otwarte okno wdziera sie porwisty wiatr." << std::endl << std::endl;
			
			if (_visited[Locations::Kitchen] == 0)
			{
				_visited[Locations::Kitchen] = 1;
				std::cout << "(Dodano n� kuchenny, pokrywka do placaka)" << std::endl << std::endl;
				Engine::getEngine().getPlayer().getBackpack().add(Weapon("Pokrywka", 2, 2));
				Engine::getEngine().getPlayer().getBackpack().add(Weapon("N� kuchenny", 1, 5));
			}
			break;

		case Locations::Garage:
			std::cout << "Gara� jak gara� nic tu nie ma opr�cz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl;
			break;

		case Locations::Attic:
			std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
			std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
			std::cout << "Podnosz�c wie coraz wy�ej spogl�dasz na stary fortepian, na kt�rym kiedy� grywa�e� z ojcem." << std::endl;
			if (_visited[Locations::Attic] == 0) std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
			
			if (_visited[Locations::Attic] == 0)
			{
				_visited[Locations::Attic] = 1;
				std::cout << "(Dodano 2x stary banda� do placaka)" << std::endl << std::endl;
				Engine::getEngine().getPlayer().getBackpack().add(Item("Staty Banda�", 2, 6));
				Engine::getEngine().getPlayer().getBackpack().add(Item("Staty Banda�", 3, 6));
			}
			break;

		case Locations::Basemant:
			if (_visited[Locations::Basemant] == 0)
			{
				std::cout << "Natrafiasz na 3 szczury" << std::endl;
				std::cout << "Nie mo�esz uciec. " << std::endl << std::endl;
				Engine::getEngine().setState(States::fight);
				_visited[Locations::Basemant] = 1;
			}
			else
			{
				std::cout << "Pokona�e� szczury" << std::endl;
				std::cout << "Dziwne d�wi�ki nasilaj� si�!?" << std::endl;
				std::cout << "Z zaciekawieniem zagl�dasz do piwnicy." << std::endl;
				std::cout << "Zapalasz �wiat�o...... " << std::endl;
				std::cout << "Wchodzisz coraz g��biej." << std::endl;
				std::cout << "Nagle wej�cie zostaje zacza�ni�te." << std::endl;
				std::cout << "Widzisz ma�e, s�odki kotki i umierasz ze szcz�cia." << std::endl;
				//std::cout << "�wiat�o zaczyna mr�ga�, widzisz tylko jakie� dziwne cienie." << std::endl;
				//std::cout << "Czujesz pot�ny, k�uj�cy bul w klatce piersiowej." << std::endl;
				//std::cout << "Umierasz ...... " << std::endl;
				std::cout << "Happy End" << std::endl << std::endl;
				// widzsz ma�ek kotki i umierasz ze szcz�cia

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
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Kitchen:
			std::cout << "1 -> Id� do sypialni" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Garage:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do sypialni" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Attic:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na sypialni" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
			break;

		case Locations::Basemant:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do sypialni" << std::endl << std::endl;
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