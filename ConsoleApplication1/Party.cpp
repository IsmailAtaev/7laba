#include "Party.h"

Party::Party(string Fname, string Lname, int YearOfBirth, string NameParty, string Biogrophy) 
	:Person(Fname, Lname, YearOfBirth)
{
	this->NameParty = NameParty;
	this->Biogrophy = Biogrophy;
}

Party::Party(const Party& obj) :Person(obj)
{
	this->NameParty = obj.NameParty;
	this->Biogrophy = obj.Biogrophy;
}

void Party::setNameParty(const string objNameParty) {
	this->NameParty = objNameParty;
}

void Party::setBiogrophy(const string objBiogrophy) {
	this->Biogrophy = objBiogrophy;
}

std::string Party::getNameParty()const{
	return this->NameParty;
}

std::string Party::getBiogrophy()const{
	return this->Biogrophy;
}

void Party::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
	std::cout << "| � |   �������     |   ���     | ��� ��������  |  ������       |       �������������        |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
}

void Party::vvodSearch()
{
	char gg = 0;
	string elem;
	int count = 0;
	cout << " ����� �� ?" << endl;
	cout << "1 �������: " << endl;
	cout << "2 ���: " << endl;
	cout << "3 ��� ��������: " << endl;
	cout << "4 �������� ������. " << endl;
	cout << "5 �������������. " << endl;
	cin >> gg;
	switch (gg)
	{
	case'1': {
		cout << " ������� �������: "; cin >> elem;
		this->setFirstname(elem);
		break;
	}
	case'2': {
		cout << " �������  ���: "; cin >> elem;
		this->setLastname(elem);
		break;
	}
	case'3': {
		cout << " ������� ��� ��������: "; cin >> count;
		this->setYear(count);
		break;
	}
	case'4': cout << " ������� �������� ������. "; cin >> this->NameParty; break;
	case'5': cout << " ������� �������������. "; cin >> this->Biogrophy; break;
	default:
		break;
	}

}

void Party::edit()
{
	char ss = 0;
	system("cls");
	rewind stdin;
	cout << "\t��������" << endl;
	cout << "____________________________________" << endl;
	cout << " 1 �������: " << endl;
	cout << " 2 ���: " << endl;
	cout << " 3 ��� ��������: " << endl;
	cout << " 4 ������: " << endl;
	cout << " 5 �������������: " << endl;
	 cin >> ss;
	system("cls");
	switch (ss)
	{
		case'1': {
			string fname;
			cout << " ������� �������: "; cin >> fname;
			this->setFirstname(fname);
			break;
		}
		case'2': {
			string lname;
			cout << " ������� ���: "; cin >> lname;
			this->setLastname(lname);
			break;
		}
		case'3': {
			int age = 0;
			cout << " ������� ��� ��������: "; cin >> age;
			this->setYear(age);
			break;
		}
		case'4': {
			string nparty;
			cout << " ������� �������� ������: "; cin >> nparty;
			this->setNameParty(nparty);
			break;
		}
		case'5': {
			string bio;
			cout << " ������� ���������: "; cin >> bio;
			this->setBiogrophy(bio);
			break;
		}
		default:
			break;
	}

}

bool Party::operator==(Party& obje)
{
	if ((this->getFirstname() == obje.getFirstname() || obje.getFirstname() == "") &&
		(this->getLastname() == obje.getLastname() || obje.getLastname() == "") &&
		(this->getYear() == obje.getYear() || obje.getYear() == 0) &&
		(this->NameParty == obje.NameParty || obje.NameParty == "") &&
		(this->Biogrophy == obje.Biogrophy || obje.Biogrophy == "")) {
		return true;
	}
	return false;
}

Party& Party::operator=(const Party& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->NameParty = obj.NameParty;
		this->Biogrophy = obj.Biogrophy;
	}
	return *this;
}

istream& operator>>(istream& in, Party& objParty)
{
	in >> dynamic_cast<Person&>(objParty);
	cout << " �������� ������. "; //in >> objParty.NameParty;
	//objParty.setNameParty(input_Str());
	cout << " ������� �������������. "; //in >> objParty.Biogrophy;
	//objParty.setBiogrophy(input_Str());
	return in;
}

ostream& operator<<(ostream& out, Party& objParty)
{
	out << dynamic_cast<Person&>(objParty);
	out << setw(17) << std::right << objParty.NameParty 
		<< setw(25) << std::right << objParty.Biogrophy;
	return out;
}