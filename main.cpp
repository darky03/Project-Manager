#include <iostream>
#include <vector>
#include <string>
#include "./includes/macros.h"
#include "./includes/strfuncs.h"
#include "./includes/types.h"
#include "./includes/structures.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

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
				commonArgument.Position = i + 1;
				std::cout << commonArgument.Position << std::endl;
				Arguments.push_back(commonArgument);
				continue;
			}
			else if(args[i] == "-d")
			{
				commonArgument.CommandName = __DELETE_PROJECT_DIR__;
				commonArgument.Position = i + 1;
				Arguments.push_back(commonArgument);
				continue;
			}
		}
		for(i = 0; i < Arguments.size(); i++)
		{
			
			if(Arguments[i].CommandName == __CREATE_PROJECT_DIR__)
			{
				struct stat info;
				extra = "./"+std::string(argv[Arguments[i].Position + 1]);
				if(info.st_mode & S_IFDIR)
				{
					std::cerr << " Project Directory already exists! " << std::endl;
					return -1;
				}
				else
				{
					mkdir(extra.c_str(),0777);		
					//std::cout << "Directory: " << extra << std::endl;

				}
				continue;
			}
			else if(Arguments[i].CommandName == __DELETE_PROJECT_DIR__)
			{
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
