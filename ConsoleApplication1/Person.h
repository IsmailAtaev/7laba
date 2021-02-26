#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Header.h"
#include "myExeption.h"

using namespace std;

class Person
{
private:
	std::string Firstname;
	std::string Lastname;
	int Year;
public:
	Person(std::string Fname = "", std::string Lname = "", int Year = 0);
	Person(const Person& objHuman);

	void setFirstname(std::string);
	void setLastname(std::string);
	void setYear(const int);
	
	std::string getFirstname()const;
	std::string getLastname()const;
	int getYear()const;

	virtual void edit() = 0;
	virtual void vvodSearch() = 0;

	friend std::istream& operator >> (std::istream& in, Person&);
	friend std::ostream& operator << (std::ostream& out, Person&);
	~Person() {	}
};