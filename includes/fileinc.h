#pragma once

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string>

class File
{
protected:
	std::fstream m_file;
	std::string m_filepath;
	virtual void RewriteChanges() = 0;
	virtual void ReadFile() = 0;
public:
	static bool DirectoryExists(const std::string &dirpath);
//	virtual
};
bool File::DirectoryExists(const std::string &dirpath)
{
	struct stat info;
	stat(dirpath.c_str(),&info);
	if(S_ISDIR(info.st_mode))
	{
		return true;
	}
	else return false;
}
