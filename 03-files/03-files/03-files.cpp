
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <string>

// this is for eliminating padding of the struct
#pragma pack(push, 1)

struct Person
{
	char name[50];
	int age;
	double weight;
};

// this is for turning padding back on
#pragma pack(pop)


int main()
{
	std::fstream file;

	std::string fileName = "sample.txt";

	file.open(fileName, std::ios::out);

	if (file.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			file << "Line " << i << ":" << i*2 << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "There was a problem with opening: " << fileName << std::endl;
	}

	file.close();

	file.open(fileName, std::ios::in);

	if (!file.is_open())
	{
		return 1;
	}

	if (file.is_open())
	{
		std::string line;
		while (file)
		{
			// parsing text
			getline(file, line, ':');
			int multiplication;
			file >> multiplication;
			
			//file.get();
			file >> std::ws;

			if (!file)
			{
				break;
			}

			//std::cout << line << "--" << multiplication << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "There was a problem with opening: " << fileName << std::endl;
	}

	Person person = {"Frodo", 220, 35};

	// Person's size is 2 bytes bigger than it should be, this is because of something called padding
	std::cout << "person's size:" << sizeof(person) << std::endl;
	std::cout << "person's name's size:" << sizeof(person.name) << std::endl;
	std::cout << "person's age's size:" << sizeof(person.age) << std::endl;
	std::cout << "person's weight's size:" << sizeof(person.weight) << std::endl;

	std::fstream newFile;

	std::string newFileName = "sample.bin";

	newFile.open(newFileName, std::ios::binary | std::ios::out);

	if (newFile.is_open())
	{
		// this is the old way
		// newFile.write((char *)&person, sizeof(Person));

		// this is the new way
		newFile.write(reinterpret_cast<char*>(&person), sizeof(Person));

		newFile.close();
	}
	else
	{
		std::cout << "Could not create file: " << newFileName << std::endl;
	}


	Person anotherPerson = {};

	newFile.open(newFileName, std::ios::binary | std::ios::in);

	if (newFile.is_open())
	{
		newFile.read(reinterpret_cast<char*>(&anotherPerson), sizeof(Person));

		newFile.close();
	}
	else
	{
		std::cout << "Could not create file: " << newFileName << std::endl;
	}

	std::cout << anotherPerson.name << ", " << anotherPerson.age << ", " << anotherPerson.weight << std::endl;


    return 0;
}

