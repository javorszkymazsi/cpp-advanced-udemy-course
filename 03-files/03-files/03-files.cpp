
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::fstream file;

	std::string fileName = "sample.txt";

	file.open(fileName, std::ios::out);

	if (file.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			file << "Line " << i << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "There was a problem with opening: " << fileName << std::endl;
	}

	file.close();

	file.open(fileName, std::ios::in);

	if (file.is_open())
	{
		std::string line;
		while (file)
		{
			getline(file, line);
			std::cout << line << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "There was a problem with opening: " << fileName << std::endl;
	}

    return 0;
}

