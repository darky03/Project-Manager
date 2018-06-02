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
			for(int i = 0; i < keys.size(); i++)
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
		std::string ReadKey(const std::string &key);
		void WriteKeyInt(const std::string &key,int value);
		void WriteKeyFloat(const std::string &key,float value);
		void WriteKeyBool(const std::string &key,bool value);
		bool ReadKeyBool(const std::string &key);
		int ReadKeyInt(const std::string &key);
		float ReadKeyFloat(const std::string &key);
		~INI();
};
INI::INI()
{
}
void INI::WriteKeyBool(const std::string &key,bool value)
{
	if(value == true)
		WriteKey(key,"true");
	else 
		WriteKey(key,"false");
}
void INI::WriteKeyFloat(const std::string &key,float value)
{
	WriteKey(key,std::to_string(value));
}
float INI::ReadKeyFloat(const std::string &key)
{
	return std::atof(ReadKey(key).c_str());
}
void INI::WriteKeyInt(const std::string &key,int value)
{
	WriteKey(key,std::to_string(value));
}
bool INI::ReadKeyBool(const std::string &key)
{
	int k = FindKey(key);
	if(k != -1)
	{
		if(keys[k].value == "true")
			return true;
		else if(keys[k].value == "false")
			return false;
		else return false;
	}
	return false;
}
int INI::ReadKeyInt(const std::string &key)
{
	return std::atoi(ReadKey(key).c_str());
}
std::string INI::ReadKey(const std::string &key)
{
	int k = FindKey(key);
	if(k != -1)
	{
		return keys[k].value;
	}
	return "";
}
void INI::WriteKey(const std::string &key,const std::string &value)
{
	int k = FindKey(key);
	if(k != -1)
	{
		keys[k].value = value;
		RewriteChanges();
	}
	else{
		KeyValueString newkey;
		newkey.key = key;
		newkey.value = value;
		keys.push_back(newkey);
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
