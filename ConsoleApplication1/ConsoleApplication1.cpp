#include <iostream>
#include "Interface.cpp"
#include "Interface.h"

/* start code :D
 1 Прогрма состоит из струтуры данных Очереди.
 2 Ромбовидная наследование.
 3 Интерфейс взаимодействия.
 4 edit code
 */

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	system("cls");
	Interface<char>::menu();
	return 0;
}