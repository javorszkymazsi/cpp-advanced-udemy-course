// 4-sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <set>
#include <iostream>
#include <string>

class Person {
public:
	int id;
	std::string name;

public:
	Person(int id, std::string name) : id(id), name(name)
	{

	}

	bool operator< (const Person& other) const
	{
		return (id < other.id);
	}

	void print() const
	{
		std::cout << "ID is " << id << " and name is " << name << "." << std::endl;
	}
};

int main()
{
	// unique set of values are stored here
	std::set<int> numbers;

	numbers.insert(23);
	numbers.insert(37);
	numbers.insert(29);
	numbers.insert(37);
	numbers.insert(35);
	numbers.insert(37);
	numbers.insert(0);
	numbers.insert(1);
	numbers.insert(37);
	numbers.insert(44);
	numbers.insert(37);

	for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "size of numbers is " << numbers.size() << std::endl;

	// count returns 0 or 1 if the value has been found or not
	if (numbers.count(37))
	{
		std::cout << "Number found." << std::endl;
	}

	std::set<Person> people;
	people.insert(Person(1, "Mike"));
	people.insert(Person(7, "Greg"));
	people.insert(Person(9, "Bob"));
	people.insert(Person(11, "Kinga"));
	
	//if there are there are objects with the same ID, you cannot add one with the same ID (in this particular situation, see how the < operator is defined)
	people.insert(Person(11, "Kiki"));
	people.insert(Person(7, "Blob"));

	for (std::set<Person>::iterator it = people.begin(); it != people.end(); ++it)
	{
		it->print();
	}

    return 0;
}

