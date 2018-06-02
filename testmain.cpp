#include <iostream>
#include "./includes/inimanager.h"
#include "./includes/strfuncs.h"
#include "./includes/assocfile.h"
#include "./includes/projectfile.h"
#include <cassert>
int main()
{
	ProjectFile pf(__PROJECT_TTYPE_PHP__,"./testfile");
	pf.Init();
	INI inifile("./test.ini",true);
	inifile.WriteKey("Test","1000");
	inifile.WriteKey("Main","1000");
	inifile.WriteKey("Somenewkey","1000");
	//inifile.WriteKeyBool("something",true);
	bool val = inifile.ReadKeyBool("something");

	//assert(val == false);
	//assert(val == false);
	return 0;
}
/*

int total,total2;
	std::string * split = strfuncs::strsplit("PHP=>>>php,php5,php7",total,"=>>>");
	std::string * split2 = strfuncs::strsplit(split[1],total2,',');
	for(int i = 0; i < total; i++)
	{
		std::cout << split[i] << std::endl;
	}
	for(int i = 0; i < total2; i++)
	{
		std::cout << split2[i] << std::endl;
	}
	std::string trimstring = "           This string will be trimmed           ";
	std::cout << strfuncs::trim(trimstring) << std::endl;
	std::string replacestring = "This string might have every 'This' in this string replaced by 'this'";
	replacestring = strfuncs::replace(replacestring,"This","this");
	replacestring = strfuncs::replace(replacestring,"this","This");
	std::cout << replacestring << std::endl;	
	replacestring = strfuncs::remove(replacestring,"This");
	std::cout << replacestring << std::endl;
	replacestring = strfuncs::trim(replacestring);
	std::cout << replacestring << std::endl;
	replacestring = strfuncs::toupper(replacestring);
	std::cout << replacestring << std::endl;
	std::cout << strfuncs::find("Test,Test,Test","Test") << std::endl;
	AssocFile m_assoc;
	m_assoc.SetAssocVal("=>");
	m_assoc.OpenAssocFile("./assocfile.txt");
	m_assoc.DisplayKeyPair();

*/
