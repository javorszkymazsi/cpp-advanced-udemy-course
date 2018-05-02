// 06-templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

// template class
template<typename T>
class Test
{
private:
	T obj;

public:
	Test(T obj)
	{
		this->obj = obj;
	}

	void print()
	{
		std::cout << obj << std::endl;
	}
};

// template function
template<typename K>
void print(K n)
{
	std::cout << "Template function: " << n << std::endl;
}

void print(int value)
{
	std::cout << "Non-template function: " << value << std::endl;
}


int main()
{
	Test<std::string> test1("Hello");
	test1.print();

	print<std::string>("Hello");
	print<int>(5);

	print(-10);
	print<unsigned int>(-10);

	print(6);
	// the template type can be left out but the template function will be used because of the <> (diamond brackets :D)
	print<>(6);

    return 0;
}

