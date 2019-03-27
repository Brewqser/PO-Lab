#pragma once

#include <string>
#include "txt_file_Body.h"

namespace TG
{
	class txt_file_Body_XML : public txt_file_Body
	{
	public:
		virtual bool Load_txt_file(std::string &file_name, std::map < std::string, int > & map);
	};

}