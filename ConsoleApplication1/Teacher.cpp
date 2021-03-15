#include "Teacher.h"
#include "Header.h"

Teacher::Teacher(std::string Fname, std::string Lname, int YearOfBirth, std::string position, std::string speciality, int listpapers)
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

void Teacher::setPosition(const std::string tempPosition) {
	this->Position = tempPosition;
}

void Teacher::setSpeciality(const std::string tempSpeciality){
	this->Speciality = tempSpeciality;
}

void Teacher::setListpapers(const int tempListpapers) {
	this->Listpapers = tempListpapers;
}

std::string Teacher::getPosition()const {
	return this->Position;
}

std::string Teacher::getSpeciality() const {
	return this->Speciality;
}

int Teacher::getListpapers() const {
	return this->Listpapers;
}

void Teacher::title() 
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
	std::cout << "| � |   �������     |   ���     | ��� ��������  |   ���������   |  �������������  |   ������.����.����. |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
}

void Teacher::edit()
{

	system("cls");
	rewind stdin;
	std::cout << " ��������" << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << " 1 �������: " << std::endl;
	std::cout << " 2 ���: " << std::endl;
	std::cout << " 3 ��� ��������: " << std::endl;
	std::cout << " 4 ���������: " << std::endl;
	std::cout << " 5 �������������: " << std::endl;
	std::cout << " 6 ���������� ������� ������:" << std::endl;
	char ss = 0;
	std::cin >> ss;
	system("cls");
	switch (ss)
	{
		case'1': {
			std::cout << " ������� �������: "; 
			this->setFirstname(input_Str(std::cin));
			break;
		}
		case'2': {
			std::cout << " ������� ���: ";
			this->setLastname(input_Str(std::cin));
			break;
		}
		case'3': {
			int r;
			std::cout << " ������� ��� ��������: "; std::cin >> r;
			this->setYear(r);
			break;
		}
		case'4': {
			std::cout << " ������� ���������: ";
			this->setPosition(input_Str(std::cin));
			break;
		}
		case'5': {
			std::cout << " ������� �������������: "; 
			this->setSpeciality(input_Str(std::cin));
			break;
		}
		case'6': {
			int m = 0;
			std::cout << " ������� ���������� ������� ������: "; std::cin >> m;
			this->setListpapers(m);
			break;
		}
		default: {
			std::cout << " ����������� ����\t������� ������������� �����" << std::endl;
			std::cin.clear(0);
			rewind(stdin);
			break;
		}
	}
}

void Teacher::vvodSearch()
{
	char gg = 0;
	std::cout << " ����� �� ?" << std::endl;
	std::cout << "1 �������: " << std::endl;
	std::cout << "2 ���: " << std::endl;
	std::cout << "3 ��� ��������: " << std::endl;
	std::cout << "4 ���������: " << std::endl;
	std::cout << "5 �������������: " << std::endl;
	std::cout << "6 ���������� ������� ������: " << std::endl;
	std::cin >> gg;
	switch (gg)
	{
	case'1': {
		std::cout << " ������� �������: ";
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case'2': {
		std::cout << " �������  ���: ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case'3': {
		int u = 0;
		std::cout << " ������� ��� ��������: "; std::cin >> u;
		this->setYear(u);
		break;
	}
	case'4': {
		std::cout << " ������� ���������: ";
		this->setPosition(input_Str(std::cin));
		break;
	}
	case'5': {
		std::cout << " ������� �������������: ";
		this->setSpeciality(input_Str(std::cin));
		break;
	}
	case'6': {
		int i = 0;
		std::cout << " ������� ���������� ������� ������: "; std::cin >> i;
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

std::istream& operator>>(std::istream& in, Teacher& obj)
{
	in >> dynamic_cast<Person&>(obj);
	std::cout << " ������� ���������: ";
	obj.setPosition(input_Str(in)); 
	std::cout << " ������� �������������: ";
	obj.setSpeciality(input_Str(in));
	std::cout << " ������� ���������� ������� ������: ";
	obj.setListpapers(input_INT(in,0,500));
	return in;
}

std::ostream& operator<<(std::ostream& out, Teacher& obj)
{
	out << dynamic_cast<Person&>(obj);
	out << std::setw(18) << std::right << obj.Position 
		<< std::setw(18) << std::right << obj.Speciality 
		<< std::setw(17) << std::right << obj.Listpapers;
	return out;
}

std::fstream& operator>>(std::fstream& f, Teacher& objT)
{
	f >> dynamic_cast<Person&>(objT)
		>> objT.Position >> objT.Speciality >> objT.Listpapers;
	return f;
}

std::fstream& operator<<(std::fstream& f, Teacher& objT)
{
	f << dynamic_cast<Person&>(objT)
		<< objT.Position << " " << objT.Speciality << " " << objT.Listpapers << std::endl;
	return f;
}
