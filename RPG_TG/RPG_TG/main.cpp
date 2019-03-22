#include <iostream>
#include <string>

#include "Definitions.h"
#include "Engine.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	TG::Engine::getEngine();

	while ( !TG::Engine::getEngine().getGameOver() )
	{
		TG::Engine::getEngine().update();

	}

	system("pause");
}