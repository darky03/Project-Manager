#pragma once
#include <vector>
#include "types.h"


typedef struct CommandArgument
{
	std::string CommandName;
//	std::string CommandParameters;
	uint32 Position;
}
CommandArgument;


typedef struct KeyValueString
{
	std::string key;
	std::string value;
}
KeyValueString;

typedef struct AssocStructure
{
	std::vector<std::string>assocs;
	std::vector<std::string>keys;
}
AssocStructure;

