#pragma once
#include"Person.h"
#include<iomanip>

class Teacher :virtual public Person
{
private:
	string Position; // ƒолжность
	string Speciality; // специальность
	int Listpapers; // список научных трудов
public:
	Teacher(string Fname = "", string Lname = "", int YearOfBirth = 0, string position = "", string speciality = "", int listpapers = 0);
	Teacher(const Teacher& objTeacher);
	Teacher& operator=(const Teacher& obj);

	void setPosition(const string);
	void setSpeciality(const string);
	void setListpapers(const int);
	
	string getPosition()const;
	string getSpeciality()const;
	int getListpapers()const;
	
	static void title();
	
	void edit()override;
	void vvodSearch()override;

	bool operator ==(Teacher& objs);
	friend istream& operator>>(istream& in, Teacher&);
	friend ostream& operator<<(ostream& out, Teacher&);

	~Teacher() { }
};