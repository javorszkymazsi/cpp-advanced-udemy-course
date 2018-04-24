#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>

class Person {
private:
	std::string name;
	int age;

public:
	// default constructor
	Person() : name(""), age(0)
	{
	}

	// copy constructor
	Person(const Person &other)
	{
		name = other.name;
		age = other.age;
	}

	// constructor that accepts the parameters
	Person(std::string name, int age) : 
		name(name), age(age)
	{		
	}

	// it has to const if the key is a class object because keys can't and shouldn't be modified
	void print() const
	{
		std::cout << name << " is " << age << " years old." << std::endl;
	}


	// std::map can't compare two Person keys (it is the map's way of storing data in order), so in order to do that we need to overwrite the < operator
	// this is the definition of comparing to Person objects
	bool operator<(const Person &other) const
	{
		if (name == other.name)
		{
			return age < other.age;
		}
		else
		{
			// strings can be compared, this is actually done by checking which is before the other in alphabetical order
			return name < other.name;
		}		
	}
};

int main()
{
	// ----------------------------------------- //
	//          object as value in a map         //
	// ----------------------------------------- //
	std::map<int, Person> people;

	people[34] = Person("Ben", 11);
	people[42] = Person("Tyron", 56);
	people[1] = Person("Bilbo", 110);

	for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); ++it)
	{
		it->second.print();
	}
	std::cout << std::endl;

	// ----------------------------------------- //
	//           object as key in a map          //
	// ----------------------------------------- //
	std::map<Person, int> folks;
	folks[Person("Amy", 35)] = 20;
	folks[Person("Anna", 29)] = 12;
	folks[Person("Sarah", 49)] = 42;

	for (std::map<Person, int>::iterator it = folks.begin(); it != folks.end(); ++it)
	{
		it->first.print();
	}

	// multimaps are used when you have a key more than once in the map. it is used very rarely though
	std::multimap<int, std::string> names;
	names.insert(std::make_pair(30, "Mike"));
	names.insert(std::make_pair(30, "Thomas"));
	names.insert(std::make_pair(30, "Ben"));
	names.insert(std::make_pair(29, "Kinga"));
	names.insert(std::make_pair(29, "Greg"));

	std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = names.equal_range(29);

	for (std::multimap<int, std::string>::iterator it = its.first; it != its.second; ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}

    return 0;
}

