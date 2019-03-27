#include "txt_file_Handle.h"


namespace TG
{
	txt_file_Handle::txt_file_Handle(EHandledFileTypes type)
	{
		switch (type)
		{
		case EHandledFileTypes::txt:
			fBodyObj = std::make_unique <txt_file_Body_txt>();

			break;

		case EHandledFileTypes::XML:
			fBodyObj = std::make_unique <txt_file_Body_XML>();
			break;

		default:
			break;
		}
	}
	
	bool txt_file_Handle::Load_txt_file(std::string file_name, std::map < std::string, int> & map)
	{
		return fBodyObj->Load_txt_file(file_name, map);
	}
}