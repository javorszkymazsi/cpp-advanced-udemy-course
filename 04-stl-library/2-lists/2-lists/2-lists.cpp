#include "stdafx.h"
#include <iostream>
#include <list>

int main()
{
	std::list<int> numbers;
	

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	
	std::list<int>::iterator it = numbers.begin();
	++it;
	numbers.insert(it, 10);
	numbers.insert(it, 5, 15);

	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << "Element is: " << *it << std::endl;
	}



    return 0;
}

