#pragma once

#include <vector>
#include <string>

class strfuncs
{
	public:
		static std::string* strsplit(const std::string &str,int &total,char del = ' ');
		static std::string* strsplit(const std::string &str,int &total,std::string delimiter = " ");
		static std::vector<int> strparts(const std::string &str,const std::string &part);
		static std::string trim(const std::string &str);
		static std::string replace(const std::string &str,const std::string &repstr,const std::string &sub);
		static std::string remove(const std::string &str,const std::string &remstr);
		static std::string toupper(const std::string &str);
		static int find(const std::string &str,const std::string &seq);

		static char toupper(const char s);
};
int strfuncs::find(const std::string &str,const std::string &seq)
{
	int i, j;
	int total = 0;
	bool complete = false;
	for(i = 0; i < str.length(); i++)
	{
		complete = false;
		if(str[i] == seq[0] && seq.length() == 1) 
		{
			total++;
			continue;
		}
		if(str[i] == seq[0])
		{
			if((i + seq.length()) > str.length()) continue;
			for(j = 1; j < seq.length(); j++)
			{
				if(seq[j] == str[i+j])
				{
					complete = true;
					continue;
				}
				else
				{
					complete = false;
					break;
				}
			}
			if(complete)
			{
				i += seq.length();
				total++;
			}
		}	
	}
	return total;
}
		
char strfuncs::toupper(const char s)
{
	if(s >= 'a' && s <= 'z')
	{
		return (s-32);
	}
	return s;
}
std::string strfuncs::toupper(const std::string &str)
{
	std::string result;
	for(int i = 0; i < str.length(); i++)
		result += toupper(str[i]);
	return result;
}
std::string strfuncs::remove(const std::string &str,const std::string &remstr)
{
	return strfuncs::replace(str,remstr,"");
}
std::string strfuncs::replace(const std::string &str,const std::string &repstr,const std::string &sub)
{
	std::string result = "";
	int last = 0;
	std::vector<int> m_parts = strfuncs::strparts(str,repstr);
	for(int i = 0; i < m_parts.size(); i++)
	{
		result += str.substr(last,m_parts[i]-last);
		result += sub;
		last = m_parts[i]+repstr.length();
	}
	result += str.substr(last,str.length() - last);
	return result;
}
std::string strfuncs::trim(const std::string& str)
{
	unsigned int i = 0,j = str.length();
	while(str[i] == ' ') i++;
	while(str[j] == ' ') j--;
	return str.substr(i,j-i);
}
std::string* strfuncs::strsplit(const std::string &str,int &total,char del)
{
	total = 0;
	int i = 0,last = 0;
	std::string *splits;
	std::vector<int> splitloc;
	for(i = 0; i < str.length(); i++)
	{
		if(str[i] == del) 
		{
			splitloc.push_back(i);
		}
	}
	total = splitloc.size() + 1;
	splits = new std::string[total];
	for(i = 0; i < splitloc.size(); i++)
	{
		splits[i] = str.substr(last,splitloc[i] - last);
		last = splitloc[i]+1;
	}
	splits[i] = str.substr(last,str.length() - last);
	return splits;
}
std::string* strfuncs::strsplit(const std::string &str,int &total,std::string delimiter)
{
	std::vector<int> locations = strfuncs::strparts(str,delimiter);
	total = locations.size() + 1;
	int i , last = 0;
	std::string *splits = new std::string[total];
	for(i = 0; i < total-1; i++)
	{
		splits[i] = str.substr(last,(locations[i]) - last);
		last = locations[i] + delimiter.length();
	}
	splits[i] = str.substr(last,str.length() - last);
	return splits;
}
std::vector<int> strfuncs::strparts(const std::string &str,const std::string &part)
{
	std::vector<int> partvec;
	int i , j;
	bool found = false;
	for(i = 0; i < str.length(); i++)
	{
		if(str[i] == part[0] && part.length() == 1)
		{
			partvec.push_back(i);
		}
		else if(str[i] == part[0])
		{	
			if((i + part.length()) > str.length()) break;
			for(j = 1; j < part.length(); j++)
			{
				if(str[i+j] == part[j])
				{
					found = true;					
					continue;
				}
				else
				{
					found = false;
					break;
				}
			}
			if(found == true)
			{
				partvec.push_back(i);
			}
			i += j;
		}	
	}
	return partvec;
}
