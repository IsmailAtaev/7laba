#pragma once
#include"Person.h"

class Party : virtual public Person
{
protected:
	string NameParty;
	string Biogrophy;
public:
	Party(string Fname = "", string Lname = "", int YearOfBirth = 0, string NameParty = "", string Biogrophy = "");
	Party(const Party& obj);

	void setNameParty(const string objNameParty);
	void setBiogrophy(const string objBiogrophy);

	string getNameParty()const;
	string getBiogrophy()const;

	static void title();

	void vvodSearch()override;
	void edit()override;

	bool operator==(Party& obje);

	Party& operator =(const Party& obj);
	friend istream& operator>>(istream& in, Party&);
	friend ostream& operator<<(ostream& out, Party&);
	~Party() { }
};