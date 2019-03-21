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
			std::cout << "Stajesz ko�o ��ka i rozgl�dasz si�." << std::endl;
			std::cout << "Za tob� znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wej�cia wisi ogromne lustro" << std::endl;
			std::cout << "Twoj� uwag� przykuwa tak�e gazeta wystaj�ca spod ��ka." << std::endl << std::endl;
		}
		if (_location == Locations::Kitchen)
		{
			std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
			std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
			std::cout << "Na ladzie ko�o kuchoenki widzisz kr�tki, ale ostry n�" << std::endl;
			std::cout << "Przez otwarte okno wdziera sie porwisty wiatr." << std::endl << std::endl;
		}
		if (_location == Locations::Garage)
		{
			std::cout << "Gara� jak gara� nic tu nie ma opr�cz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl;
		}
		if (_location == Locations::Attic)
		{
			std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
			std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
			std::cout << "Podnosz�c wie coraz wy�ej spogl�dasz na stary fortepian, na kt�rym kiedy� grywa�e� z ojcem." << std::endl;
			std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
		}
		if (_location == Locations::Basemant)
		{
			std::cout << "Dziwne d�wi�ki nasilaj� si�!?" << std::endl;
			std::cout << "Z zaciekawieniem zagl�dasz do piwnicy." << std::endl;
			std::cout << "Zapalasz �wiat�o...... " << std::endl;
			std::cout << "Wchodzisz coraz g��biej" << std::endl;
			std::cout << "Nagle wej�cie zostaje zacza�ni�te" << std::endl;
			std::cout << "�wiat�o zaczyna mr�ga�, widzisz tylko jakie� dziwne cienie." << std::endl;
			std::cout << "Czujesz pot�ny, k�uj�cy bul w klatce piersiowej." << std::endl;
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
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Kitchen)
		{
			std::cout << "1 -> Id� do sypialni" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Garage)
		{
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do sypialni" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
			
			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Attic)
		{
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na sypialni" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Basemant)
		{
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do sypialni" << std::endl << std::endl;

			std::cin >> tmp;
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Bedroom;
		}

	}
}