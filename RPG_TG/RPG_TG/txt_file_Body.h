#pragma once

#include <map>
#include <string>
#include <vector>

namespace TG
{
	class txt_file_Body
	{
	public:
		virtual bool Load_txt_file(std::string &file_name, std::map < std::string , int > & map) = 0;

		virtual ~txt_file_Body() = default;
	};

}

