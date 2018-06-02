#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#include "./includes/projectfile.h"
#include "./includes/fileinc.h"
#include "./includes/macros.h"
#include "./includes/strfuncs.h"
#include "./includes/types.h"
#include "./includes/structures.h"

void CheckAppDirAndCreate();

int main(int argc,char **argv)
{
	CheckAppDirAndCreate();
	
	std::string extra[2]; // Extra for holding the string color
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
				Arguments.push_back(commonArgument);
				continue;
			}
			else if(args[i] == "-t")
			{
				commonArgument.CommandName = __PROJECT_TYPE__;
				commonArgument.Position = i + 1;
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
				
				extra[0] = "./"+std::string(argv[Arguments[i].Position + 1]);
				extra[1] = extra[0];
				if(!File::DirectoryExists(extra[0]))
				{
					mkdir(extra[0].c_str(),0777);		
				}
				else std::cout << "Directory already exists! " << std::endl;
				continue;
			}
			else if(Arguments[i].CommandName == __PROJECT_TYPE__)
			{
				extra[0] = std::string(argv[Arguments[i].Position + 1]);
				uint8 filetype = -1;
				
				if(extra[0] == __PROJECT_TYPE_CPP__)
				{
					if(File::DirectoryExists(extra[1]))	
					{
						filetype = __PROJECT_TTYPE_CPP__;
					}
				}
				else if(extra[0] == __PROJECT_TYPE_C__)
				{
					if(File::DirectoryExists(extra[1]))	
					{
						filetype = __PROJECT_TTYPE_C__;
					}
				}
				else if(extra[0] == __PROJECT_TYPE_PHP__)
				{
					if(File::DirectoryExists(extra[1]))	
					{
						filetype = __PROJECT_TTYPE_PHP__;	
					}
				
				}
				if(filetype != -1)
				{
					ProjectFile pf(filetype,extra[1]);
					pf.Init();
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

void CheckAppDirAndCreate()
{
	struct stat info;
	stat("~/.projectmanager/",&info);
	if(info.st_mode & S_IFDIR)
	{
		//Load Settings for the application
		
	}
	else
	{
		struct passwd *pw = getpwuid(getuid());
		std::string dirpath = std::string(pw->pw_dir)+"/.projectmanager";
		int dir= mkdir(dirpath.c_str(),0777);
	
	}
}
