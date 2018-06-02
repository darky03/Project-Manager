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
	bool val = inifile.ReadKeyBool("something");
	return 0;
}
