// 05-operator-overloading.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>

class Person {
private:
	int id;
	std::string name;

public:
	Person() : id(0), name("")
	{

	}

	Person(int id, std::string name) : id(id), name(name)
	{

	}

	void print() const
	{
		std::cout << id << ": " << name << std::endl;
	}

	// assignment operator
	const Person &operator=(const Person &other)
	{
		std::cout << "Assignment running" << std::endl;

		id = other.id;
		name = other.name;

		return *this;
	}

	Person(const Person &other)
	{
		std::cout << "Copy constructor running" << std::endl;
		/*id = other.id;
		name = other.name;*/
		*this = other;
	}
};

int main()
{
	Person person1(29, "Greg");
	Person person2(24, "Kinga");
	person2.print();

	person2 = person1;
	person2.print();

	// copy initialization. it doesn't invoke the = operator (and its overloaded method) but the copy constructor
	Person person3 = person2;
	person3.print();


	// WHAAAATTT???!!! this is totally valid
	// Person person3;
	// person3 = person2 = person1;
	/*person1.print();
	person2.print();*/
	//person3.print();

	// this is the exact same as person3 = person2
	/*person3.operator=(person2);
	person3.print();*/
	
    return 0;
}

