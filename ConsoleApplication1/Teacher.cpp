#include "Teacher.h"

Teacher::Teacher(string Fname, string Lname, int YearOfBirth, string position, string speciality, int listpapers)
	:Person(Fname, Lname, YearOfBirth)
{
	this->Position = position;
	this->Speciality = speciality;
	this->Listpapers = listpapers;
}

Teacher::Teacher(const Teacher& objTeacher) :Person(objTeacher)
{
	this->Position = objTeacher.Position;
	this->Speciality = objTeacher.Speciality;
	this->Listpapers = objTeacher.Listpapers;
}

void Teacher::setPosition(const string tempPosition) {
	this->Position = tempPosition;
}

void Teacher::setSpeciality(const string tempSpeciality){
	this->Speciality = tempSpeciality;
}

void Teacher::setListpapers(const int tempListpapers) {
	this->Listpapers = tempListpapers;
}

string Teacher::getPosition()const {
	return this->Position;
}

string Teacher::getSpeciality() const {
	return this->Speciality;
}

int Teacher::getListpapers() const {
	return this->Listpapers;
}

void Teacher::title() 
{
	cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << endl;
	cout << "| � |   �������     |   ���     | ��� ��������  |   ���������   |  �������������  |   ������.����.����. |" << endl;
	cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << endl;
}

void Teacher::edit()
{

	system("cls");
	rewind stdin;
	cout << " ��������" << endl;
	cout << "____________________________________" << endl;
	cout << " 1 �������: " << endl;
	cout << " 2 ���: " << endl;
	cout << " 3 ��� ��������: " << endl;
	cout << " 4 ���������: " << endl;
	cout << " 5 �������������: " << endl;
	cout << " 6 ���������� ������� ������:" << endl;
	char ss = 0;
	cin >> ss;
	system("cls");
	switch (ss)
	{
		case'1': {
			cout << " ������� �������: "; 
			this->setFirstname(input_Str(cin));
			break;
		}
		case'2': {
			cout << " ������� ���: ";
			this->setLastname(input_Str(cin));
			break;
		}
		case'3': {
			int r;
			cout << " ������� ��� ��������: "; cin >> r;
			this->setYear(r);
			break;
		}
		case'4': {
			cout << " ������� ���������: ";
			this->setPosition(input_Str(cin));
			break;
		}
		case'5': {
			cout << " ������� �������������: "; 
			this->setSpeciality(input_Str(cin));
			break;
		}
		case'6': {
			int m = 0;
			cout << " ������� ���������� ������� ������: "; cin >> m;
			this->setListpapers(m);
			break;
		}
		default: {
			cout << " ����������� ����\t������� ������������� �����" << endl;
			cin.clear(0);
			rewind(stdin);
			break;
		}
	}
}

void Teacher::vvodSearch()
{
	char gg = 0;
	cout << " ����� �� ?" << endl;
	cout << "1 �������: " << endl;
	cout << "2 ���: " << endl;
	cout << "3 ��� ��������: " << endl;
	cout << "4 ���������: " << endl;
	cout << "5 �������������: " << endl;
	cout << "6 ���������� ������� ������: " << endl;
	cin >> gg;
	switch (gg)
	{
	case'1': {
		cout << " ������� �������: ";
		this->setFirstname(input_Str(cin));
		break;
	}
	case'2': {
		cout << " �������  ���: ";
		this->setLastname(input_Str(cin));
		break;
	}
	case'3': {
		int u = 0;
		cout << " ������� ��� ��������: "; cin >> u;
		this->setYear(u);
		break;
	}
	case'4': {
		cout << " ������� ���������: ";
		this->setPosition(input_Str(cin));
		break;
	}
	case'5': {
		cout << " ������� �������������: ";
		this->setSpeciality(input_Str(cin));
		break;
	}
	case'6': {
		int i = 0;
		cout << " ������� ���������� ������� ������: "; cin >> i;
		this->setListpapers(i);
		break;
	}
	default: 
		break;
	}
}

Teacher& Teacher::operator=(const Teacher& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->Position = obj.Position;
		this->Speciality = obj.Speciality;
		this->Listpapers = obj.Listpapers;
	}
	return *this;
}

bool Teacher::operator==(Teacher& obj)
{
	if ((this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&
		(this->getPosition() == obj.getPosition() || obj.getPosition() == "") &&
		(this->getSpeciality() == obj.getSpeciality() || obj.getSpeciality() == "") &&
		(this->getListpapers() == obj.getListpapers() || obj.getListpapers() == 0)) {
		return true;
	}
	return false;
}

istream& operator>>(istream& in, Teacher& obj)
{
	in >> dynamic_cast<Person&>(obj);
	cout << " ������� ���������: "; 
	obj.setPosition(input_Str(in)); 
	cout << " ������� �������������: ";
	obj.setSpeciality(input_Str(in));
	cout << " ������� ���������� ������� ������: ";
	obj.setListpapers(input_INT(in,0,500));
	return in;
}

ostream& operator<<(ostream& out, Teacher& obj)
{
	out << dynamic_cast<Person&>(obj);
	out << setw(18) << std::right << obj.Position 
		<< setw(18) << std::right << obj.Speciality 
		<< setw(17) << std::right << obj.Listpapers;
	return out;
}