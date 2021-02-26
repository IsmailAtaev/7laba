#pragma once
#include "myExeption.h"
#include <istream>
#include "Person.h"

inline std::string input_Str(std::istream& in)
{
	std::string ss;
	bool flag = false;
	do {
		try {
			flag = false;
			rewind(stdin);
			std::getline(in, ss, '\n');

			for (int i = 0; i < ss.length(); i++) {
				
				if ((ss[i] < 'a' || ss[i] > 'z')  && (ss[i] < 'A' || ss[i] > 'Z'))
					throw myExeption_Inpit(56, " Некоруктный ввод\n Введите Английские буквы !!!");
			}
		}
		catch (myExeption_Inpit ex) {
			flag = true;
			ex.Print();
			system("pause");
			std::cout << " Введите повторно\n ";
		}
		
	} while (flag);
	system("cls");

	return ss;
}


inline int input_INT(std::istream& in) {
	int flags = 0;
	int temp = 0;
	do {
		try
		{
			flags = 0;
			rewind(stdin);
			in >> temp;
			flags = std::cin.rdstate();
			if ((flags & std::ios::failbit) || in.peek() != '\n') {
				throw myExeption_Inpit(4005, " Некоруктный ввод\n Введите только целые числа  !!!");
			}
		}
		catch (myExeption_Inpit& ex) {
			temp = 0;
			ex.Print();
			in.clear(0);
			system("pause");	
			flags = 1;
			std::cout << " Введите повторно\n ";
		}
		catch (...) {
			flags = 1;
			in.clear(0);
			std::cout << " Что-то пошло не так Вызвын catch(...) " << std::endl;
		}
	} while (flags);
	system("cls");
	return temp;
}
