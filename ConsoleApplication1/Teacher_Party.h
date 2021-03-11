#pragma once
#include "Party.h"
#include "Teacher.h"

class Teacher_Party : public Teacher, public Party
{
private:
	std::string Rol_In_Party;
public:
	Teacher_Party(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0,std::string position = "", std::string speciality = "", int listpapers = 0,std::string NameParty = "", std::string Biogrophy = "",std::string Rol_In_Party = "");
	void setRol_In_Party(const std::string);
	Teacher_Party& operator =(const Teacher_Party& obj);

	std::string getRol_In_Party()const;
	 static void title();
	
	friend std::istream& operator>>(std::istream& in, Teacher_Party&);
	friend std::ostream& operator<<(std::ostream& out, Teacher_Party&);
	bool operator ==(Teacher_Party& obj);

	void edit()override;
	void vvodSearch()override;

	~Teacher_Party() { }
};