#pragma once

#include <memory>
#include <map>
#include "txt_file_Body.h"
#include "txt_file_Body_txt.h"
#include "txt_file_Body_XML.h"

namespace TG
{
	class txt_file_Handle
	{
		
	private:
		using BodyPtr = std::unique_ptr <txt_file_Body>;

		BodyPtr fBodyObj;

	public:

		enum class EHandledFileTypes { txt, XML };
		txt_file_Handle(EHandledFileTypes type);
		bool Load_txt_file(std::string file_name, std::map < std::string, int > & map);
		
		virtual ~txt_file_Handle() = default;
		
	};
}
