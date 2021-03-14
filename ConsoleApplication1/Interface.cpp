#pragma once
#include "Interface.h"

template<class T>
inline void Interface<T>::menu()
{
    char ch = 0;
    do {
        system("cls");
        std::cout << " 1. Учитель." << std::endl;
        std::cout << " 2. Партия." << std::endl;
        std::cout << " 3. Учитель Партия. " << std::endl;
        std::cout << " 0. Выход. ";   std::cin >> ch;
        system("cls");
        switch (ch) {
            case'1': {
                std::string filename = "Teacher.txt";
                Interface<Teacher> objTeacher(filename);
                objTeacher.Funck();
                break;
            }
            case'2': {
                std::string filename = "Party.txt";
                Interface<Party> objParty(filename);
                objParty.Funck();
                break;
            }
            case'3': {
                std::string filename = "Teacher_Party.txt";
                Interface<Teacher_Party> objTeacher_Party(filename);
                objTeacher_Party.Funck();
                break;
            }
            default: break;
        }
    } while (ch != '0');
}

template<class T>
void Interface<T>::Funck()
{
    Queue<T> obj;
    T value{};
    T result;
    char ch = NULL;
    int flags = 0;
    do {
        system("cls");
        std::cout << " ---===[ Выбор меню ]===---" << std::endl;
        std::cout << " 1.  Добавить элемент." << std::endl;
        std::cout << " 2.  Вывод на экран." << std::endl;
        std::cout << " 3.  Удалить." << std::endl;
        std::cout << " 4.  Удалить и возвратить." << std::endl;
        std::cout << " 5.  Удалить Все." << std::endl;
        std::cout << " 6.  Поиск." << std::endl;
        std::cout << " 7.  Изменить." << std::endl;
        std::cout << " 8.  Сортировать по Фамили." << std::endl;
        std::cout << " 9.  Читать из файла." << std::endl;
        std::cout << " 10. Запись в файла." << std::endl;
        std::cout << " 0.  Возврат в главный меню.\t  "; 
        flags = input_INT(cin,-1,11);
        system("cls");
        switch (flags)
        {
            case 1: {
                rewind stdin;
                cin >> value;
                obj.Enqueue(value);
                break;
            }
            case 2: {
                if (!obj.Empty()) {
                    obj.Title();
                    obj.show();
                    break;
                }
                cout << "Очередь пуст!!! " << endl;
                break;
            }
            case 3 : {
                if (!obj.Empty()) {
                    obj.Dequeue1();
                    break;
                }
                std::cout << "Очередь пуст!!! " << endl;
                break;
              }
            case 4: {
                if (!obj.Empty()) {
                    result = obj.Dequeue();
                    cout << " Удаленный данные:  " << result << endl;
                }
                else cout << "  Пуст! " << endl;
                break;
            }
            case 5: {
                obj.Clear();
                break;
            }
            case 6: {
                if (!obj.Empty()) {
                    Queue<T>* elem = obj.sSearch();
                    obj.Title();
                    elem->show();
                    delete elem;
                }
                else std::cout << "  Пуст! " << std::endl;
                break;
            }
            case 7: {
                obj.Edit();
                break;
            }
            case 8: {
               
                for (int i = 0; i < obj.GetSize(); i++)
                {
                    for (int j =  i + 1; j < obj.GetSize(); j++)
                    {
                        if ((obj)[i].getFirstname() > (obj)[j].getFirstname())
                        {
                            T temp = obj[i];
                            obj[i] = obj[j];
                            obj[j] = temp;
                        }
                    }
                }
                break;
            }
            case 9: {
                FileTXT<T> file(fileN);
                T data;
                obj.Clear();



                while (1) 
                {
                    if (file.REndFile())
                        break;
                    file.readRrcordInFile(data);
                    obj.Enqueue(data);
                }



                break;
            }

            case 10: {
                FileTXT<T> file(fileN);
                while (obj.GetSize() != 0)
                {
                    T data = obj.Dequeue();
                    file.writeRecordInFile(data);
                }
                break;
            }
            default: break;
        }
        system("pause");
    } while (ch != '0');
}
