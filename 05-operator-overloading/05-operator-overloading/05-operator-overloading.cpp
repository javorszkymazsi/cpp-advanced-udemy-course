// 05-operator-overloading.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Complex.h"

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

	std::cout << std::endl;

	// WHAAAATTT???!!! this is totally valid
	// Person person3;
	// person3 = person2 = person1;
	/*person1.print();
	person2.print();*/
	//person3.print();

	// this is the exact same as person3 = person2
	/*person3.operator=(person2);
	person3.print();*/
	
	Complex c1(2, 3);
	std::cout << c1 << std::endl;

	Complex c2(4, 5);
	std::cout << c2 << std::endl;

	c2 = c1;

	Complex c3 = c1 + c2;
	std::cout << c3 << std::endl;

	c3 = c3 + 2;
	std::cout << c3 << std::endl;

	if (c1 == c2)
	{
		std::cout << "These are equal" << std::endl;
	}
	else
	{
		std::cout << "Nope, not equal" << std::endl;
	}

	std::cout << *c3 << std::endl;

    return 0;
}

