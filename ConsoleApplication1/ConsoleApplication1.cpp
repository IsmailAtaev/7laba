#include <iostream>
#include "Interface.cpp"
#include "Interface.h"

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	system("cls");
	Interface<char>::menu();
	return 0;
}