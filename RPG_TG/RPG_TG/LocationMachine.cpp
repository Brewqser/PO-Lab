#include "LocationMachine.h"

#include <iostream>

#include "Arena.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Bedroom;
		for (int i = 0; i < amountOfLocations; i++)
		{
			_search.push_back(0);
		}

		std::cout << "Budzisz si� w swoim ��ku." << std::endl;
		std::cout << "Nagle s�yszysz dziwne d�wi�ki dobiekaj�ce z piwnicy." << std::endl;
		std::cout << "Zdezori�towany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "�e masz schowanie gdzie� w domu co� w razie takiej sytu�acji." << std::endl << std::endl;
		std::cout << "Sterowanie ( obowi�zuje 'globalnie'):" << std::endl;
		std::cout << "t - menu porusznia" << std::endl;
		std::cout << "p - menu postaci" << std::endl;
		std::cout << "s - przeszukanie danej lokacji" << std::endl;
		std::cout << "inne cyfry i znaki - przemieszcanie si� po menu/ lokacjach / itp." << std::endl << std::endl;
	}

	void LocationMachine::info(Player &pl)
	{
		if (_location == Locations::Bedroom)
		{
			std::cout << "Stajesz ko�o ��ka i rozgl�dasz si�." << std::endl;
			std::cout << "Za tob� znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wej�cia wisi ogromne lustro" << std::endl;
			std::cout << "Twoj� uwag� przykuwa tak�e gazeta wystaj�ca spod ��ka." << std::endl;
			std::cout << std::endl;
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Kitchen)
		{
			if (_search[Locations::Kitchen] == 0)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na kuchence po�o�ony jest garczek" << std::endl;
				std::cout << "Na ladzie ko�o kuchenki widzisz kr�tki, ale ostry n�" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 1)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na ladzie ko�o kuchenki widzisz kr�tki, ale ostry n�" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 2)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na kuchence po�o�ony jest garczek" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 3)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl << std::endl;

			}
			std::cout << "1 -> Id� do sypialni" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

		}

		if (_location == Locations::Garage)
		{
			std::cout << "Gara� jak gara� nic tu nie ma opr�cz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl << std::endl;

			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do sypialni" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Attic)
		{
			
			if (_search[Locations::Attic] == 0)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Podnosz�c wie coraz wy�ej spogl�dasz na stary fortepian." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 1)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 2)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Podnosz�c sie coraz wy�ej spogl�dasz na stary fortepian." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 3)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl << std::endl;
			}

			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na sypialni" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Basemant)
		{
			if (_search[Locations::Basemant] == 0)
			{
				// Arena;
				std::cout << "Nartafiasz na 3 szczury." << std::endl << std::endl;
				Arena(pl,3);

				_search[Locations::Basemant] = 1;
			}
			if (_search[Locations::Basemant] == 1)
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
			}
		}
	}

	void LocationMachine::travel(int tmp)
	{
		//std::cout << tmp << std::endl;
		if (_location == Locations::Bedroom)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;

		}
		else if (_location == Locations::Kitchen)
		{
			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Garage)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Attic)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
		}
		/*
		if( _location == Locations::Basemant)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Bedroom;
		}
		*/

		///std::cout << _location << std::endl;
	}

	void LocationMachine::search(Backpack &bp)
	{
		if (_location == Locations::Bedroom)
		{
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
		}

		if (_location == Locations::Kitchen)
		{
			if (_search[Locations::Kitchen] == 0)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> N� kuchenny" <<  std::endl;
				std::cout << "2 -> Pokrywka" << std::endl  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("N� kuchenny", 5, 2));
					_search[Locations::Kitchen] = 2;
				}
				if (a == 2)
				{
					bp.add(Weapon("Pokrywka", 2, 2));
					_search[Locations::Kitchen] = 1;
				}
			}
			else if (_search[Locations::Kitchen] == 1)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> N� kuchenny" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("N� kuchenny", 5, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Kitchen] == 2)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Pokrywka"  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("Pokrywka", 2, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Kitchen] == 3)
			{
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			}

		}

		if (_location == Locations::Garage)
		{
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
		}

		if (_location == Locations::Attic)
		{
			if (_search[Locations::Attic] == 0)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Stary Banda�" << std::endl;
				std::cout << "2 -> Banda�" << std::endl  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Item("Stary Banda�",3,2));
					_search[Locations::Kitchen] = 2;
				}
				if (a == 2)
				{
					bp.add(Weapon("Banda�", 5, 2));
					_search[Locations::Kitchen] = 1;
				}
			}
			else if (_search[Locations::Attic] == 1)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Stary Banda�"  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Item("Stary Banda�", 3, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Attic] == 2)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Banda�" << std::endl << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("Banda�", 5, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Attic] == 3)
			{
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			}
		}
		/*
		if (_location == Locations::Basemant)
		{

		}
		*/
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::setSearch(int s, int i)
	{
		_search[i] = s;
	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	std::vector <int>  &LocationMachine::getSearch()
	{
		return _search;
	}
}