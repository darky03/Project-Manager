#pragma once

#include <vector>
#include <string>

class strfuncs
{
	public:
		static std::string* strsplit(const std::string &str,int &total,char del = ' ');
};
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
