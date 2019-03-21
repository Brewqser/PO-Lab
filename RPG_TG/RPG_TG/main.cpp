#include <iostream>
#include <string>

#include "Definitions.h"
#include "Engine.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	while (!TG::Engine::getEngine().getGameOver())
	{
		TG::Engine::getEngine().printLocation();

		if ( !TG::Engine::getEngine().getGameOver())  TG::Engine::getEngine().changeLocation();
	}

	system("pause");
}