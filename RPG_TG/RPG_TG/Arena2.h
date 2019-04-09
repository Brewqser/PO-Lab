#pragma once
#include <string>
#include "enemyHandle.h"

namespace TG
{
	class Arena2
	{
	public:
		Arena2(std::string enemy);

		void fight();

	private:
		std::unique_ptr <enemyHandle> _enemy;
	};
}
