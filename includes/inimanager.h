#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structures.h"
#include "fileinc.h"
class INI : public File
{
	private:
		std::vector<KeyValueString> keys;
		void RewriteChanges()
		{
			for(int i = 0; i < keys.size(); i++)
			{
				
			}
		}
	public:
		INI();
		INI(const std::string &fp,bool forcecreate = false);
		~INI();
};
INI::INI()
{
}
INI::INI(const std::string &fp,bool forcecreate)
{
	m_filepath = fp;
	m_file.open(m_filepath.c_str(),std::fstream::in | std::fstream::out);
	if(!m_file.good())
	{
		m_file.close();
		if(forcecreate)
		{
			m_file.open(m_filepath.c_str(),std::fstream::app);
			m_file.close();
		}
		else
		{
			std::cerr << "[FILE] " << fp << " was not present to open it , force create was disabled!" << std::endl;
		}
	}
}
INI::~INI()
{
	if(m_file.is_open())
	{
		m_file.close();
	}
}
