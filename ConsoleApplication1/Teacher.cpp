#include "Teacher.h"

Teacher::Teacher(string Fname, string Lname, int YearOfBirth, string position, string speciality, int listpapers) :Person(Fname, Lname, YearOfBirth)
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
	cout << "| № |   Фамилия     |   Имя     | Год Рождения  |   Должность   |  Специальность  |   Список.науч.труд. |" << endl;
	cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << endl;
}

void Teacher::edit()
{
	char ss = 0;
	system("cls");
	rewind stdin;
	cout << " Изменить" << endl;
	cout << "____________________________________" << endl;
	cout << " 1 Фамилию: " << endl;
	cout << " 2 Имя: " << endl;
	cout << " 3 Год рождения: " << endl;
	cout << " 4 Должность: " << endl;
	cout << " 5 Специальность: " << endl;
	cout << " 6 Количество научных трудов:" << endl;
	cin >> ss;
	system("cls");
	switch (ss)
	{
		case'1': {
			string fname;
			cout << " Введите фамилию: "; cin >> fname;
			this->setFirstname(fname);
			break;
		}
		case'2': {
			string lname;
			cout << " Введите имя: "; cin >> lname;
			this->setLastname(lname);
			break;
		}
		case'3': {
			int age = 0;
			cout << " Введите год рождения: "; cin >> age;
			this->setYear(age);
			break;
		}
		case'4': {
			string position;
			cout << " Введите Должность: "; cin >> position;
			this->setPosition(position);
			break;
		}
		case'5': {
			string speciati;
			cout << " Введите специальность: "; cin >> speciati;
			this->setSpeciality(speciati);
			break;
		}
		case'6': {
			int listpapers = 0;
			cout << " Введите количество научных трудов: "; cin >> listpapers;
			this->setListpapers(listpapers);
			break;
		}
		default:
			break;
	}
}

void Teacher::vvodSearch()
{
	char gg = 0;
	string elem;
	int count = 0;
	cout << " Поиск по ?" << endl;
	cout << "1 Фамилию: " << endl;
	cout << "2 Имя: " << endl;
	cout << "3 Год рождения: " << endl;
	cout << "4 Должность: " << endl;
	cout << "5 Специальность: " << endl;
	cout << "6 Количество научных трудов: " << endl;
	cin >> gg;
	switch (gg)
	{
	case'1': {
		cout << " Введите фамилию: "; cin >> elem;
		this->setFirstname(elem);
		break;
	}
	case'2': {
		cout << " Введите  имя: "; cin >> elem;
		this->setLastname(elem);
		break;
	}
	case'3': {
		cout << " Введите год рождения: "; cin >> count;
		this->setYear(count);
		break;
	}
	case'4': {
		cout << " Введите Должность: "; cin >> elem;
		this->setPosition(elem);
		break;
	}
	case'5': {
		string speciality;
		cout << " Введите специальность: "; cin >> speciality;
		this->setSpeciality(speciality);
		break;
	}
	case'6': {
		cout << " Введите количество научных трудов: "; cin >> count;
		this->setListpapers(count);
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
	cout << " Введите Должность: "; 
	obj.setPosition(input_Str(in)); 
	cout << " Введите специальность: ";
	obj.setSpeciality(input_Str(in));
	cout << " Введите количество научных трудов: ";  //in >> obj.Listpapers;
	obj.setListpapers(input_INT(in));
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