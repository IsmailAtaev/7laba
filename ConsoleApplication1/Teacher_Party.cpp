#include "Teacher_Party.h"
#include <iomanip>

Teacher_Party::Teacher_Party(std::string Fname, std::string Lname, int YearOfBirth, std::string position, std::string speciality, int listpapers, std::string NameParty, std::string Biogrophy, std::string Rol_In_Party)
	:Teacher(Fname, Lname, YearOfBirth, position, speciality, listpapers), Party(Fname, Lname, YearOfBirth, NameParty, Biogrophy)
{
	this->Rol_In_Party = Rol_In_Party;
}

void Teacher_Party::setRol_In_Party(const std::string obj) {
	this->Rol_In_Party = obj;
}

std::string Teacher_Party::getRol_In_Party()const  {
	return this->Rol_In_Party;
}

void Teacher_Party::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
	std::cout << "| № |   Фамилия     |   Имя     | Год Рождения  |   Должность   |  Специальность  |   Список.науч.труд. |    партии     |       автобиография       |    Рол в партии     |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
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
	std::cout << " Изменить " << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << " 1 Фамилию: " << std::endl;
	std::cout << " 2 Имя: " << std::endl;
	std::cout << " 3 Год рождения: " << std::endl;
	std::cout << " 4 Должность: " << std::endl;
	std::cout << " 5 Специальность: " << std::endl;
	std::cout << " 6 Количество научных трудов:" << std::endl;
	std::cout << " 7 Партия: " << std::endl;
	std::cout << " 8 Автобиография: " << std::endl;
    std::cin >> ss;
	system("cls");
	switch (ss)
	{
		case'1': {
			std::string fname;
			std::cout << " Введите фамилию: "; std::cin >> fname;
			this->setFirstname(fname);
			break;
		}
		case'2': {
			std::string lname;
			std::cout << " Введите имя: "; std::cin >> lname;
			this->setLastname(lname);
			break;
		}
		case'3': {
			int age = 0;
			std::cout << " Введите год рождения: "; std::cin >> age;
			this->setYear(age);
			break;
		}
		case'4': {
			std::string position;
			std::cout << " Введите Должность: "; std::cin >> position;
			this->setPosition(position);
			break;
		}
		case'5': {
			std::string speciati;
			std::cout << " Введите специальность: "; std::cin >> speciati;
			this->setSpeciality(speciati);
			break;
		}
		case'6': {
			int listpapers = 0;
			std::cout << " Введите количество научных-трудов: "; std::cin >> listpapers;
			this->setListpapers(listpapers);
			break;
		}
		case'7': {
			std::string nparty;
			std::cout << " Введите название партии: "; std::cin >> nparty;
			this->setNameParty(nparty);
			break;
		}
		case'8': {
			std::string bio;
			std::cout << " Введите биография: "; std::cin >> bio;
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
	std::string elem;
	int count = 0;
	std::cout << " Поиск по ?" << std::endl;
	std::cout << "1 Фамилию: " << std::endl;
	std::cout << "2 Имя: " << std::endl;
	std::cout << "3 Год рождения: " << std::endl;
	std::cout << "4 Должность: " << std::endl;
	std::cout << "5 Специальность: " << std::endl;
	std::cout << "6 Количество научных трудов: " << std::endl;
	std::cout << "7 Название партии. " << std::endl;
	std::cout << "8 Автобиография. " << std::endl;
	std::cout << "9 Рол в партии. " << std::endl;
	std::cin >> gg;
	switch (gg)
	{
		case'1': {
			std::cout << " Введите фамилию: "; std::cin >> elem;
			this->setFirstname(elem);
			break;
		}
		case'2': {
			std::cout << " Введите  имя: "; std::cin >> elem;
			this->setLastname(elem);
			break;
		}
		case'3': {
			std::cout << " Введите год рождения: "; std::cin >> count;
			this->setYear(count);
			break;
		}
		case'4': {
			std::cout << " Введите Должность: "; std::cin >> elem;
			this->setPosition(elem);
			break;
		}
		case'5': {
			std::cout << " Введите специальность: "; std::cin >> elem;
			this->setPosition(elem);
			break;
		}
		case'6': {
			std::cout << " Введите количество научных трудов: "; std::cin >> count;
			this->setListpapers(count);
			break;
		}
		case'7': std::cout << " Введите название партии. "; std::cin >> this->NameParty; break;
		case'8': std::cout << " Введите автобиография. "; std::cin >> this->Biogrophy; break;
		case'9': std::cout << " Введите рол в партии. "; std::cin >> this->Rol_In_Party; break;
		default:
			break;
	}
}

std::istream& operator>>(std::istream& in, Teacher_Party& RolParty)
{
	in >> dynamic_cast<Teacher&>(RolParty);
	std::cout << " Введите название партии. ";
	RolParty.setNameParty(input_Str(in));
	std::cout << " Введите автобиография. ";
	RolParty.setBiogrophy(input_Str(in));
	std::cout << " Введите рол в партии. ";
	RolParty.setRol_In_Party(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, Teacher_Party& objParty)
{
	out << dynamic_cast<Teacher&>(objParty);
	out << std::setw(20) << std::right << objParty.NameParty
		<< std::setw(25) << std::right << objParty.Biogrophy
		<< std::setw(23) << std::right << objParty.Rol_In_Party << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& finTP, Teacher_Party& objTP)
{
	finTP >> dynamic_cast<Teacher&>(objTP)
		>> objTP.NameParty
		>> objTP.Biogrophy
		>> objTP.Rol_In_Party;
	return finTP;
}

std::ofstream& operator<<(std::ofstream& foutTP, Teacher_Party& objTP)
{
	foutTP << dynamic_cast<Person&>(objTP)
		<< objTP.getPosition() <<" "
		<< objTP.getSpeciality() << " "
		<< objTP.getListpapers() << " "
		<< objTP.NameParty << " "
		<< objTP.Biogrophy << " "
		<< objTP.Rol_In_Party << std::endl;
	return foutTP;
}



std::fstream& operator>>(std::fstream& f, Teacher_Party& objTP)
{
	f >> dynamic_cast<Teacher&>(objTP)
		>> objTP.NameParty >> objTP.Biogrophy >> objTP.Rol_In_Party;
	return f;
}

std::fstream& operator<<(std::fstream& f, Teacher_Party& objTP)
{

	f << dynamic_cast<Person&>(objTP)
		<< objTP.getPosition() << " "
		<< objTP.getSpeciality() << " "
		<< objTP.getListpapers() << " "
		<< objTP.NameParty << " "
		<< objTP.Biogrophy << " "
		<< objTP.Rol_In_Party << std::endl;
	return f;
}