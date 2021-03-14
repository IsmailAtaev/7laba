#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Header.h"
#include "myExeption.h"


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


	friend std::ifstream& operator >> (std::ifstream& finP, Person& objP);
	friend std::ofstream& operator << (std::ofstream& foutP,Person& objP);


	friend std::fstream& operator>> (std::fstream& f, Person& objP);
	friend std::fstream& operator<< (std::fstream& f, Person& objP);
	
	~Person() {	}
};