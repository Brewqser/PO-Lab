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
			_state.push_back(0);
		}

		std::cout << "Budzisz si� ranny w swoim ��ku." << std::endl;
		std::cout << "Nagle s�yszysz dziwne d�wi�ki dobiekaj�ce z piwnicy." << std::endl;
		std::cout << "Zdezori�towany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "�e masz schowanie gdzie� w domu co� w razie takiej sytu�acji." << std::endl << std::endl;
		std::cout << "Sterowanie: cyfry zgodnie z przypisanym znaczeniem." << std::endl << std::endl;
	}

	void LocationMachine::info(Player &pl,bool &gr)
	{
		switch (_location)
		{
		case Locations::Bedroom:
			std::cout << "Stajesz ko�o ��ka i rozgl�dasz si�." << std::endl;
			std::cout << "Za tob� znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wej�cia wisi ogromne lustro" << std::endl;
			std::cout << "Twoj� uwag� przykuwa tak�e gazeta wystaj�ca spod ��ka." << std::endl;
			std::cout << std::endl;
			break;

		case Locations::Kitchen:
			if (_state[Locations::Kitchen] == 0)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na kuchence po�o�ony jest garczek" << std::endl;
				std::cout << "Na ladzie ko�o kuchenki widzisz kr�tki, ale ostry n�" << std::endl << std::endl;
			}
			if (_state[Locations::Kitchen] == 1)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na ladzie ko�o kuchenki widzisz kr�tki, ale ostry n�" << std::endl << std::endl;
			}
			if (_state[Locations::Kitchen] == 2)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl;
				std::cout << "Na kuchence po�o�ony jest garczek" << std::endl << std::endl;
			}
			if (_state[Locations::Kitchen] == 3)
			{
				std::cout << "Kuchnia wygl�da inaczej ni� zwykle." << std::endl;
				std::cout << "Jednakowo� nic nie wydaje si� wychodzi� poza schemat" << std::endl << std::endl;
			}

			break;

		case Locations::Garage:

			std::cout << "Gara� jak gara� nic tu nie ma opr�cz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl << std::endl;
			break;

		case Locations::Attic:
			if (_state[Locations::Attic] == 0)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Podnosz�c wie coraz wy�ej spogl�dasz na stary fortepian." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
			}
			if (_state[Locations::Attic] == 1)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne �mieci kt�re tam le��." << std::endl << std::endl;
			}
			if (_state[Locations::Attic] == 2)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl;
				std::cout << "Podnosz�c sie coraz wy�ej spogl�dasz na stary fortepian." << std::endl << std::endl;
			}
			if (_state[Locations::Attic] == 3)
			{
				std::cout << "Wychodzisz po stromych, skrzypi�cych schodach, kt�re ledwo" << std::endl;
				std::cout << "ale jednak wytrzymuj� tw�j ci�ar." << std::endl << std::endl;
			}

			break;

		case Locations::Basemant:
			if (_state[Locations::Basemant] == 0)
			{
				std::cout << "Nartafiasz na 3 szczury." << std::endl << std::endl;
				Arena(pl,3,gr);
				if (pl.getStatistics().getHp() <= 0)
				{
					gr = 0;
				}
				_state[Locations::Basemant] = 1;
			}
			if (_state[Locations::Basemant] == 1 && gr == 1)
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
				_state[Locations::Basemant] = 2;
				gr = 0;
			}
		}
	}

	void LocationMachine::manage(States &s ,Backpack &bp)
	{
		std::cout << "Opcje: " << std::endl;
		std::cout << "1 -> prouszanie" << std::endl;
		std::cout << "2 -> przeszukaj lokacje" << std::endl;
		std::cout << "3 -> menu postaci" << std::endl;

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 1 || tmp > 3);

		if (tmp == 1)
		{
			this->travel();
		}
		if (tmp == 2)
		{
			this->search(bp);
		}
		if (tmp == 3)
		{
			s = States::player;
		}
	}

	void LocationMachine::travel()
	{
		int tmp;
		switch (_location)
		{
		case Locations::Bedroom:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Kitchen:
			std::cout << "1 -> Id� do sypialni" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Garage:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do sypialni" << std::endl;
			std::cout << "3 -> Id� na strych" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Attic:
			std::cout << "1 -> Id� do kuchnii" << std::endl;
			std::cout << "2 -> Id� do gara�u" << std::endl;
			std::cout << "3 -> Id� na sypialni" << std::endl;
			std::cout << "4 -> Id� do piwnicy" << std::endl << std::endl;

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		}
	}

	void LocationMachine::search(Backpack &bp)
	{
		int tmp;
		Weapon w1("N� kuchenny", 5, 2);
		Weapon w2("Pokrywka", 2, 2);
		Item i1("Stary Banda�", 3, 2);
		Item i2("Banda�", 5, 2);

		switch (_location)
		{
		case Locations::Bedroom:
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			break;

		case Locations::Kitchen:
			switch (_state[Locations::Kitchen])
			{
			case 0:
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "-N� kuchenny" << std::endl;
				std::cout << "-Pokrywka" << std::endl;
				std::cout << "Co bierzesz: " << std::endl;
				std::cout << "0 -> nic" << std::endl;
				std::cout << "1 -> ";
				w1.info();
				std::cout << "2 -> ";
				w2.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 2);

				if (tmp == 1)
				{
					if (bp.add(w1)) _state[Locations::Kitchen] = 2;
				}
				if (tmp == 2)
				{
					if (bp.add(w2)) _state[Locations::Kitchen] = 1;
				}

				break;

			case 1:
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "-N� kuchenny" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): " << std::endl;
				std::cout << "1 -> ";
				w1.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(w1)) _state[Locations::Kitchen] = 3;
				}
				break;

			case 2:
				std::cout << "Znajdujesz:" << std::endl; 
				std::cout << "-Pokrywka" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): " << std::endl;
				std::cout << "1 -> ";
				w2.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(w2)) _state[Locations::Kitchen] = 3;
				}
				break;

			case 3:
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
				break;
			}

			break;

		case Locations::Garage:
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			break;

		case Locations::Attic:
			switch (_state[Locations::Attic])
			{
			case 0:
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "-Stary Banda�" << std::endl;
				std::cout << "-Banda�" << std::endl;
				std::cout << "Co bierzesz: " << std::endl;
				std::cout << "0 -> nic" << std::endl;
				std::cout << "1 -> ";
				i1.info();
				std::cout << "2 -> ";
				i2.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 2);

				if (tmp == 1)
				{
					if (bp.add(i1)) _state[Locations::Attic] = 2;
				}
				if (tmp == 2)
				{
					if (bp.add(i2)) _state[Locations::Attic] = 1;
				}

				break;

			case 1:
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "-Stary Banda�" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): " << std::endl;
				std::cout << "1 -> ";
				i1.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(i1)) _state[Locations::Attic] = 3;
				}
				break;

			case 2:
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "-Banda�" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): " << std::endl;
				std::cout << "1 -> ";
				i2.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(i2)) _state[Locations::Attic] = 3;
				}
				break;

			case 3:
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
				break;
			}
		}
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::setState(int s, int i)
	{
		_state[i] = s;
	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	std::vector <int>  &LocationMachine::getState()
	{
		return _state;
	}

}