#include "stdafx.h"

#include <iostream>
#include <string>
#include <exception>

void somethingWentWrong();

void moreErrorsOccured();

class ExceptionClass : public std::exception
{
public:
	virtual const char* what() const
	{
		return "Something bad happened.";
	}
};

class Test
{
public:
	void goesWrong() {
		bool error = true;

		if (error)
		{
			throw std::bad_alloc();
		}
	}
};

int main()
{
	try
	{
		moreErrorsOccured();
	}
	// right order of catching exceptions starting from child class to parent class
	catch (ExceptionClass &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}

void somethingWentWrong()
{
	bool error1 = true;
	bool error2 = true;

	if (error1)
	{
		throw ExceptionClass();
	}

	if (error2)
	{
		throw std::exception();
	}
}

void moreErrorsOccured()
{
	somethingWentWrong();
}