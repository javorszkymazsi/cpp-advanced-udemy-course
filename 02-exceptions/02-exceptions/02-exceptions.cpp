#include "stdafx.h"

#include <iostream>
#include <string>

void somethingWentWrong();

void moreErrorsOccured();


int main()
{
	try
	{
		somethingWentWrong();
	}
	catch (int e)
	{
		std::cout << "ERROR" << e << " has occured." << std::endl;
	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
	}

    return 0;
}

void somethingWentWrong()
{
	bool error1 = false;
	bool error2 = true;

	if (error1)
	{
		throw 1;
	}

	if (error2)
	{
		throw std::string("A string error has occured");
	}
}

void moreErrorsOccured()
{
	somethingWentWrong();
}