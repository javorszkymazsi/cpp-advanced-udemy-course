#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>

int main()
{
	std::map<std::string, int> persons;

	persons["Mike"] = 20;
	persons["Tina"] = 22;
	persons["Ben"] = 28;

	if (persons.find("Sue") != persons.end())
	{
		std::cout << "Sue found" << std::endl;
	}
	else
	{
		std::cout << "Key not found" << std::endl;
	}

	for (std::map<std::string, int>::iterator it = persons.begin(); it != persons.end(); ++it)
	{
		std::cout << it->first << "'s age is " << it->second << std::endl;
	}

    return 0;
}

