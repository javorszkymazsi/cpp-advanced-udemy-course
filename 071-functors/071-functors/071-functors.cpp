// 071-functors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

// this is a functor
struct MatchTest
{
	bool operator()(std::string &text)
	{
		return text == "lion";
	}
};

void check(std::string text, MatchTest &test)
{
	if (test(text))
	{
		std::cout << "It's a match" << std::endl;
	}
	else
	{
		std::cout << "It's NOT a match" << std::endl;
	}
}

int main()
{
	MatchTest mt;
	check("dgdfglion", mt);

    return 0;
}

