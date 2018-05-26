#pragma once

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

