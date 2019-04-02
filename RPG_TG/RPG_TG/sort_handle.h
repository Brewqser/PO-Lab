#pragma once

#include <memory>
#include "Weapon.h"

namespace TG
{
	enum  EHandlesort { name, weight, damage};

	class sort_handle
	{

	private:
		int en;

	public:

		void set(int i);
		sort_handle();
		bool  operator()(Weapon i, Weapon j);

	};
}
