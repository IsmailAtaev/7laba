#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	string Firstname;
	string Lastname;
	int Year;
public:
	Person(string Fname = "", string Lname = "", int Year = 0);
	Person(const Person& objHuman);

	void setFirstname(string);
	void setLastname(string);
	void setYear(const int);
	
	string getFirstname()const;
	string getLastname()const;
	int getYear()const;

	virtual void edit() = 0;
	virtual void vvodSearch() = 0;

	friend istream& operator >> (istream& in, Person&);
	friend ostream& operator << (ostream& out, Person&);
	~Person() {	}
};