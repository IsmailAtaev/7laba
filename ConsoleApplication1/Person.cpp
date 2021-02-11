#pragma once 
#include "Person.h"
#include <iomanip>
#include "INPUT-STR.cpp"

Person::Person(string Fname, string Lname, int Year)
{
	this->Firstname = Fname;
	this->Lastname = Lname;
	this->Year = Year;
}

Person::Person(const Person& objHuman)
{
	this->Firstname = objHuman.Firstname;
	this->Lastname = objHuman.Lastname;
	this->Year = objHuman.Year;
}

void Person::setFirstname(string strFirstname) {
	this->Firstname = strFirstname;
}

void Person::setLastname(string  strLastname) {
	this->Lastname = strLastname;
}

void Person::setYear(const int year) {
	this->Year = year;
}

string Person::getFirstname()const {
	return this->Firstname;
}

string Person::getLastname()const {
	return this->Lastname;
}

int Person::getYear() const {
	return this->Year;
}

istream& operator>>(istream& in, Person& objp)
{
	cout << " ¬ведите фамилию: "; 
	string se;
	se = input_Str();
	objp.setFirstname(se);
	
	//in >> objp.Firstname;
	cout << " ¬ведите  им€: "; in >> objp.Lastname;
	cout << " ¬ведите год рождени€: "; in >> objp.Year;
	return in;
}

ostream& operator<<(ostream& out, Person& objp)
{
	out << setw(15) << std::right << objp.Firstname
		<< setw(13) << std::right << objp.Lastname 
		<< setw(14) << std::right << objp.Year;
	return out;
}