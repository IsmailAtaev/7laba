#include "Teacher_Party.h"
#include <iomanip>

Teacher_Party::Teacher_Party(string Fname, string Lname, int YearOfBirth, string position, string speciality, int listpapers, string NameParty, string Biogrophy, string Rol_In_Party)
	:Teacher(Fname, Lname, YearOfBirth, position, speciality, listpapers), Party(Fname, Lname, YearOfBirth, NameParty, Biogrophy)
{
	this->Rol_In_Party = Rol_In_Party;
}

void Teacher_Party::setRol_In_Party(const string obj) {
	this->Rol_In_Party = obj;
}

string Teacher_Party::getRol_In_Party()const  {
	return this->Rol_In_Party;
}

void Teacher_Party::title()
{
	cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << endl;
	cout << "| № |   Фамилия     |   Имя     | Год Рождения  |   Должность   |  Специальность  |   Список.науч.труд. |    партии     |       автобиография       |    Рол в партии     |" << endl;
	cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << endl;
}

bool Teacher_Party::operator==(Teacher_Party& obj)
{
	if ((this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&	
		(this->getPosition() == obj.getPosition() || obj.getPosition() == "") &&
		(this->getSpeciality() == obj.getSpeciality() || obj.getSpeciality() == "") &&	
		(this->getListpapers() == obj.getListpapers() || obj.getListpapers() == 0) &&
		(this->getNameParty() == obj.getNameParty() || obj.getNameParty() == "") &&
		(this->getBiogrophy() == obj.getBiogrophy() || obj.getBiogrophy() == "") &&
		(this->getRol_In_Party() == obj.getRol_In_Party() || obj.getRol_In_Party() == "")) {
		return true;
	}
	return false;
}

Teacher_Party& Teacher_Party::operator=(const Teacher_Party& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->setPosition(obj.getPosition());
		this->setSpeciality(obj.getSpeciality());
		this->setListpapers(obj.getListpapers());
		this->NameParty = obj.NameParty;
		this->Biogrophy = obj.Biogrophy;
		this->Rol_In_Party = obj.Rol_In_Party;
	}
	return *this;
}

void Teacher_Party::edit()
{
	char ss = 0;
	system("cls");
	rewind stdin;
	cout << " Изменить " << endl;
	cout << "____________________________________" << endl;
	cout << " 1 Фамилию: " << endl;
	cout << " 2 Имя: " << endl;
	cout << " 3 Год рождения: " << endl;
	cout << " 4 Должность: " << endl;
	cout << " 5 Специальность: " << endl;
	cout << " 6 Количество научных трудов:" << endl;
	cout << " 7 Партия: " << endl;
	cout << " 8 Автобиография: " << endl;
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
			cout << " Введите количество научных-трудов: "; cin >> listpapers;
			this->setListpapers(listpapers);
			break;
		}
		case'7': {
			string nparty;
			cout << " Введите название партии: "; cin >> nparty;
			this->setNameParty(nparty);
			break;
		}
		case'8': {
			string bio;
			cout << " Введите биография: "; cin >> bio;
			this->setBiogrophy(bio);
			break;
		}
		default:
			break;
	}
}

void Teacher_Party::vvodSearch()
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
	cout << "7 Название партии. " << endl;
	cout << "8 Автобиография. " << endl;
	cout << "9 Рол в партии. " << endl;
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
			cout << " Введите специальность: "; cin >> elem;
			this->setPosition(elem);
			break;
		}
		case'6': {
			cout << " Введите количество научных трудов: "; cin >> count;
			this->setListpapers(count);
			break;
		}
		case'7': cout << " Введите название партии. "; cin >> this->NameParty; break;
		case'8': cout << " Введите автобиография. "; cin >> this->Biogrophy; break;
		case'9': cout << " Введите рол в партии. "; cin >> this->Rol_In_Party; break;
		default:
			break;
	}
}

istream& operator>>(istream& in, Teacher_Party& RolParty)
{
	in >> dynamic_cast<Teacher&>(RolParty);
	cout << " Введите название партии. "; in >> RolParty.NameParty;
	cout << " Введите автобиография. "; in >> RolParty.Biogrophy; 
	cout << " Введите рол в партии. "; in >> RolParty.Rol_In_Party;
	return in;
}

ostream& operator<<(ostream& out, Teacher_Party& objParty)
{
	out << dynamic_cast<Teacher&>(objParty);
	out << setw(20) << std::right << objParty.NameParty
		<< setw(25) << std::right << objParty.Biogrophy
		<< setw(23) << std::right << objParty.Rol_In_Party << endl;
	return out;
}