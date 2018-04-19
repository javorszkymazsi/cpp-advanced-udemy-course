#include "stdafx.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> numbers;

	int capacity = numbers.capacity();

	for (int i = 0; i < 100000; ++i)
	{
		numbers.push_back(i);
		if (numbers.capacity() != capacity)
		{
			std::cout << "Capacity is changed from " << capacity << " to " << numbers.capacity() << " when element size was " << numbers.size() << std::endl;
			capacity = numbers.capacity();
		}
	}

	numbers.resize(200);

	std::cout << "Size of the vector is now: " << numbers.size() << std::endl;
	std::cout << "Capacity of the vector is now: " << numbers.capacity() << std::endl;

	std::vector<std::vector<int>> numbersVectors;




    return 0;
}

