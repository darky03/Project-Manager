#include <iostream>
#include <string>
#include "./includes/strfuncs.h"

int main(int argc,char **argv)
{
	std::string str = "Test test test";
	int total;
	std::string *splits = strfuncs::strsplit(str,total,' ');
	for(int i = 0; i < total; i++)
	{
		std::cout << splits[i] << std::endl;
	}
	return 0;
}
