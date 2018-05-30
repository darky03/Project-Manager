#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "strfuncs.h"
#include "structures.h"
#include "fileinc.h"
class INI : public File
{
	private:
		std::vector<KeyValueString> keys;
		void RewriteChanges()
		{
			m_file.close();
			m_file.open(m_filepath.c_str(),std::fstream::trunc | std::fstream::out);
			m_file.close();
			m_file.open(m_filepath.c_str(),std::fstream::in | std::fstream::out);
			for(int i = 0; i < keys.size(); i++)
			{
				m_file << keys[i].key << "=" << keys[i].value << std::endl;
			}
		}
		void ReadFile()
		{
			if(m_file.is_open())
			{
				KeyValueString pair;
				std::string fileline;
				std::string *splits;
				int total;
				m_file.seekp(0);
				m_file.seekg(0);
				while(!m_file.eof())
				{
					getline(m_file,fileline);				
					splits = strfuncs::strsplit(fileline,total,'=');
					if(total > 1)
					{
						pair.key = splits[0];
						pair.value = splits[1];
						keys.push_back(pair);
						std::cout << splits[0] << " = " << splits[1] << std::endl;
					}
				}
			}
		}
		int FindKey(const std::string &key)
		{
			for(int i = 0; i < keys.length(); i++)
			{
				if(keys[i].key == key)
				{
					return i;
				}
			}			
			return -1;	
		}
	public:
		INI();
		INI(const std::string &fp,bool forcecreate = false);
		void WriteKey(const std::string &key, const std::string &value);		
		~INI();
};
INI::INI()
{
}
void INI::WriteKey(const std::string &key,const std::string &value)
{
	int k = FindKey(key);
	if(k != -1)
	{
		keys[k].value = value;
		RewriteChanges();
	}
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
	else
	{
		ReadFile();
	}
}
INI::~INI()
{
	if(m_file.is_open())
	{
		m_file.close();
	}
}
