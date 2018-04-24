// 5-stack_and_queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stack>
#include <queue>
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;

public:
	Person(std::string name) : name(name)
	{

	}

	~Person()
	{
		//std::cout << "Object destroyed" << std::endl;
	}

	void print() const
	{
		std::cout << name << std::endl;
	}
};

int main()
{
	// LIFO = last in first out
	std::stack<Person> personStack;

	personStack.push(Person("Mike"));
	personStack.push(Person("Kinga"));
	personStack.push(Person("Greg"));

	// reference can't be used here because one you've popped it, it will be unreliable
	/*Person &person = personStack.top();
	person.print();
	personStack.pop();*/

	while (personStack.size() > 0)
	{
		Person person = personStack.top();
		person.print();
		personStack.pop();
	}

	std::cout << std::endl;


	// FIFO = first in first out
	std::queue<Person> personQueue;

	personQueue.push(Person("Mike"));
	personQueue.push(Person("Kinga"));
	personQueue.push(Person("Greg"));

	personQueue.back().print();

	std::cout << std::endl;

	while (personQueue.size() > 0)
	{
		Person person = personQueue.front();
		person.print();
		personQueue.pop();
	}
	

    return 0;
}

