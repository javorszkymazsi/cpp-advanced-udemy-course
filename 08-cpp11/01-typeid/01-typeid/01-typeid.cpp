// 01-typeid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <typeinfo>

class T
{
public:
	T(int num) : member(num) {}
	~T() {}

private:
	int member;
};

// this looks weird
auto test() -> int
{
	return 7;
}

// but in this case it might be useful
template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2)
{
	return value1 + value2;
}

int main()
{
	std::string value;
	T t(2);

	// it prints out "class T". this is because of name mangling in c++11
	std::cout << typeid(t).name() << std::endl;

	// declare new variables with an existing type
	decltype(value) name = "bob";

	// it's a string!!
	std::cout << typeid(value).name() << std::endl;


	auto num = 2;
	std::cout << typeid(num).name() << std::endl;

	std::cout << test() << std::endl;

    return 0;
}

