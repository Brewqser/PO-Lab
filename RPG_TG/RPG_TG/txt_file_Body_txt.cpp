#include "txt_file_Body_txt.h"

#include <fstream>
#include <iostream>

namespace TG
{
	bool txt_file_Body_txt::Load_txt_file(std::string &file_name, std::map < std::string, int > &map)
	{
		std::fstream plik;
		std::string nazwa = file_name + ".txt";
		plik.open( nazwa , std::ios::in | std::ios::out);

		if (plik.good() == true)
		{
			std::string key;
			int dana;
			while (plik >> key >> dana)
			{
				//std::cout << key << " " << dana << std::endl;
				map[key] = dana;
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
}