#pragma once

#include "Enemy.h"
#include <vector>
#include "Engine.h"

namespace TG
{
	class Arena
	{
	private:
		std::vector <Enemy> _enemies;

	public:
		Arena();
		Arena(int n);

		void fight();


	};
}
