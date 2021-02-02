#pragma once
#include "Party.h"
#include "Teacher.h"

class Teacher_Party : public Teacher, public Party
{
private:
	string Rol_In_Party;
public:
	Teacher_Party(string Fname = "", string Lname = "", int YearOfBirth = 0,string position = "", string speciality = "", int listpapers = 0,string NameParty = "", string Biogrophy = "",string Rol_In_Party = "");
	void setRol_In_Party(const string);
	Teacher_Party& operator =(const Teacher_Party& obj);

	string getRol_In_Party()const;
	 static void title();
	
	friend istream& operator>>(istream& in, Teacher_Party&);
	friend ostream& operator<<(ostream& out, Teacher_Party&);
	bool operator ==(Teacher_Party& obj);

	void edit()override;
	void vvodSearch()override;

	~Teacher_Party() { }
};