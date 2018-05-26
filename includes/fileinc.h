#pragma once

#include <fstream>
#include <string>

class File
{
protected:
	std::fstream m_file;
	std::string m_filepath;
	virtual void RewriteChanges() = 0;
public:
//	virtual
};
