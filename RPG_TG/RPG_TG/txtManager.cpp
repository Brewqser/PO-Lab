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

	void txtManager::print(Enemy *e)
	{
		this->print(e->getStatistics().getName(), 1);
		this->print(&e->getStatistics());
	}

	void txtManager::print(Backpack *b)
	{
		this->print("bp1", 0);
		std::cout << b->getFreeWeigth();
		this->print("bp2", 1);
	}

	void txtManager::attack(std::string s, int a)
	{
		this->print("att", 0);
		std::cout << s << std::endl;
	}

	txtManager::txtManager()
	{
		setlocale(LC_ALL, "");
		std::string key;

		key = "f";
		_txt[key].push_back("Znajdujesz:");

		key = "nf";
		_txt[key].push_back("Nic nie znajdujesz.");

		key = "attt";
		_txt[key].push_back("1 -> IdŸ do kuchnii");
		_txt[key].push_back("2 -> IdŸ do gara¿u");
		_txt[key].push_back("3 -> IdŸ do sypialni");
		_txt[key].push_back("4 -> IdŸ do piwnicy");

		key = "gart";
		_txt[key].push_back("1 -> IdŸ do kuchnii");
		_txt[key].push_back("2 -> IdŸ do sypialni");
		_txt[key].push_back("3 -> IdŸ na strych");
		_txt[key].push_back("4 -> IdŸ do piwnicy");

		key = "kitt";
		_txt[key].push_back("1 -> IdŸ do sypialni");
		_txt[key].push_back("2 -> IdŸ do gara¿u");
		_txt[key].push_back("3 -> IdŸ na strych");
		_txt[key].push_back("4 -> IdŸ do piwnicy");

		key = "bedt";
		_txt[key].push_back("1 -> IdŸ do kuchnii");
		_txt[key].push_back("2 -> IdŸ do gara¿u");
		_txt[key].push_back("3 -> IdŸ na strych");
		_txt[key].push_back("4 -> IdŸ do piwnicy");

		key = "loc opt";
		_txt[key].push_back("Opcje: ");
		_txt[key].push_back("1 -> prouszanie");
		_txt[key].push_back("2 -> przeszukaj lokacje");
		_txt[key].push_back("3 -> menu postaci");

		key = "bas";
		_txt[key].push_back("Pokona³eœ szczury");
		_txt[key].push_back("Dziwne dŸwiêki nasilaj¹ siê!?");
		_txt[key].push_back("Z zaciekawieniem zagl¹dasz do piwnicy.");
		_txt[key].push_back("Zapalasz œwiat³o......");
		_txt[key].push_back("Wchodzisz coraz g³êbiej.");
		_txt[key].push_back("Nagle wejœcie zostaje zaczaœniête.");
		_txt[key].push_back("Widzisz ma³e, s³odki kotki i umierasz ze szczêœcia.");
		_txt[key].push_back("Happy End");

		key = "attmess";
		_txt[key].push_back("Nartafiasz na 3 szczury.");

		key = "att3";
		_txt[key].push_back("Podnosz¹c wie coraz wy¿ej spogl¹dasz na stary fortepian.");

		key = "att2";
		_txt[key].push_back("Jednak przez przypadek kierujesz wzrok na inne œmieci które tam le¿¹.");

		key = "att1";
		_txt[key].push_back("Wychodzisz po stromych, skrzypi¹cych schodach, które ledwo");
		_txt[key].push_back("ale jednak wytrzymuj¹ twój ciê¿ar.");;

		key = "gar";
		_txt[key].push_back("Gara¿ jak gara¿ nic tu nie ma oprócz wypasionego samochodu");
		_txt[key].push_back("A przynajmniej narazie xd.");

		key = "kit3";
		_txt[key].push_back("Na ladzie ko³o kuchenki widzisz krótki, ale ostry nó¿");

		key = "kit2";
		_txt[key].push_back("Na kuchence po³o¿ony jest garczek");

		key = "kit1";
		_txt[key].push_back("Kuchnia wygl¹da inaczej ni¿ zwykle.");
		_txt[key].push_back("Jednakowo¿ nic nie wydaje siê wychodziæ poza schemat");

		key = "bed";
		_txt[key].push_back("Stajesz ko³o ³ó¿ka i rozgl¹dasz siê.");
		_txt[key].push_back("Za tob¹ znajduje sie szafka nocna.");
		_txt[key].push_back("Na przeciwko wejœcia wisi ogromne lustro");
		_txt[key].push_back("Twoj¹ uwagê przykuwa tak¿e gazeta wystaj¹ca spod ³ó¿ka.");

		key = "start";
		_txt[key].push_back("Budzisz siê ranny w swoim ³ó¿ku.");
		_txt[key].push_back("Nagle s³yszysz dziwne dŸwiêki dobiekaj¹ce z piwnicy.");
		_txt[key].push_back("Zdezoriêtowany wstajesz i przypominasz sobie, ");
		_txt[key].push_back("¿e masz schowanie gdzieœ w domu coœ w razie takiej sytu³acji. ");
		_txt[key].push_back("Sterowanie: cyfry zgodnie z przypisanym znaczeniem.");

		key = "bpm";
		_txt[key].push_back("Otwierasz plecak co robisz:");
		_txt[key].push_back("0 -> nic ");
		_txt[key].push_back("1 -> przegl¹dam plecak ");
		_txt[key].push_back("2 -> zwalniam miejsce ");

		key = "bpr";
		_txt[key].push_back("Co chcesz usun¹æ: ");
		_txt[key].push_back("0 -> nic ");

		key = "tmc";
		_txt[key].push_back("Za ma³o miejsca w plecaku.");

		key = "addw";
		_txt[key].push_back("Do plecaka dodano ");

		key = "wp";
		_txt[key].push_back("Bronie:");

		key = "it";
		_txt[key].push_back("Przedmioty:");

		key = "bp12";
		_txt[key].push_back(" wagi.");

		key = "bp1";
		_txt[key].push_back("W plecaku zmieœci sie jeszcze ");

		key = "Szczur";
		_txt[key].push_back("Szczur");

		key = "///";
		_txt[key].push_back("//////////////////////////////////////////////////////////////////////");

		key = "patt";
		_txt[key].push_back("Atakujesz: ");

		key = "Arena opt";
		_txt[key].push_back("Opcje:");
		_txt[key].push_back("1 -> atak");
		_txt[key].push_back("2 -> akcje");

		key = "twoje";
		_txt[key].push_back("Twoje ");

		key = "att";
		_txt[key].push_back("Attakuje za ");

		key = "w8";
		_txt[key].push_back("Czeka");
		
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