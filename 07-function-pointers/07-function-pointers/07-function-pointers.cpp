// 07-function-pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

void test()
{
	std::cout << "Hello" << std::endl;
}

void printInt(int value)
{
	std::cout << "The int's value is " << value << std::endl;
}

bool isItBigger(int value1, int value2)
{
	return (value1 < value2);
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
bool match(std::string str)
{
	return (str.size() == 3);
}

// this is how you can you a function pointer in a function declaration
int countStrings(std::vector<std::string> &texts, bool(*match)(std::string str))
{
	int counter = 0;
	for (auto text : texts)
	{
		if (match(text))
		{
			++counter;
		}
	}
	return counter;
}

int main()
{
	test();

	// this is a pointer to a function with the type of void and accepts no parameters
	void (*pTest)();

	// now it points to void test()
	pTest = &test;
	// the function is called with the pointer
	(*pTest)();

	// OR
	// the name of the function is an address in itself
	pTest = test;
	// and there's no need to dereference the pointer
	pTest();
	
	printInt(4);
	void (*pNewTest)(int) = printInt;
	pNewTest(6);


	if (isItBigger(4, 5))
	{
		std::cout << "Yes, it's bigger" << std::endl;
	}
	else
	{
		std::cout << "Well, it's actually smaller" << std::endl;
	}

	auto (*funcPointer)(int, int) = isItBigger;
	if (funcPointer(9, 5))
	{
		std::cout << "Yes, it's bigger" << std::endl;
	}
	else
	{
		std::cout << "Well, it's actually equal or smaller" << std::endl;
	}


	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////

	std::vector<std::string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("five");

	std::cout << count_if(texts.begin(), texts.end(), match) << std::endl;

	std::cout << "There are " << countStrings(texts, match) << " strings which are 3 characters long" << std::endl;

    return 0;
}

