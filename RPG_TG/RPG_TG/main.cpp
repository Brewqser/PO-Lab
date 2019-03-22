#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Definitions.h"
#include "Engine.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	while ( !TG::Engine::getEngine().getGameOver() )
	{
		TG::Engine::getEngine().update();
	}
	system("pause");
}