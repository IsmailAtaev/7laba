#include <iostream>
#include "Interface.cpp"
#include "Interface.h"

// start code :D

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	system("cls");
	Interface<char>::menu();
	return 0;
}