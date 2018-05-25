#include <iostream>
#include <vector>
#include <string>
#include "./includes/strfuncs.h"

#define		__CREATE_PROJECT_DIR__		"CREATE"
#define		__PROJECT_TYPE__		"TYPE"
#define		__PROJECT_MAIN_AUTHOR__		"AUTHOR"
#define		__INIT_PROJECT_BUILD_FILE__	"INITB"
#define		__DELETE_PROJECT_DIR__		"DELETE"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct CommandArgument
{
	std::string CommandName;
	uint32 Position;
}
CommandArgument;

int main(int argc,char **argv)
{
	
	std::string extra; // Extra for holding the string color
	CommandArgument commonArgument;
	std::vector<CommandArgument> Arguments;
	std::vector<std::string> args;
	int i = 0;
	for(i = 1; i < argc; i++)
		args.push_back(std::string(argv[i]));
	if(args.size() > 0)
	{
		for(i = 0; i < args.size(); i++)
		{
			if(args[i] == "-c")
			{
				commonArgument.CommandName = __CREATE_PROJECT_DIR__;
				commonArgument.Position = i;
				Arguments.push_back(commonArgument);
				continue;
			}
			else if(args[i] == "-d")
			{
				commonArgument.CommandName = __DELETE_PROJECT_DIR__;
				commonArgument.Position = i;
				Arguments.push_back(commonArgument);
				continue;
			}
		}
		
	}
	else
	{
		std::cerr << "No args provided!" << std::endl;
		return -1;
	}
	return 0;
}
