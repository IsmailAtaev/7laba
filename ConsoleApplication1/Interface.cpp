#pragma once
#include "Interface.h"

template<class T>
inline void Interface<T>::menu()
{
    char ch = 0;
    do {
        system("cls");
        cout << " 1. Учитель." << endl;
        cout << " 2. Партия." << endl;
        cout << " 3. Учитель Партия. " << endl;
        cout << " 0. Выход. ";   cin >> ch;
        system("cls");
        switch (ch) {
            case'1': {
                Interface<Teacher> objTeacher;
                objTeacher.Funck();
                break;
            }
            case'2': {
                Interface<Party> objParty;
                objParty.Funck();
                break;
            }
            case'3': {
                Interface<Teacher_Party> objTeacher_Party;
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
    do {
        system("cls");
        cout << " ---===[ Выбор меню ]===---" << endl;
        cout << " 1. Добавить элемент." << endl;
        cout << " 2. Вывод на экран." << endl;
        cout << " 3. Удалить." << endl;
        cout << " 4. Удалить и возвратить." << endl;
        cout << " 5. Удалить Все." << endl;
        cout << " 6. Поиск." << endl;
        cout << " 7. Изменить." << endl;
        cout << " 8. Сортировать по Фамили." << endl;
        cout << " 0. Возврат в главный меню.\t  "; cin >> ch;
        system("cls");
        switch (ch)
        {
            case'1': {
                rewind stdin;
                cin >> value;
                obj.Enqueue(value);
                break;
            }
            case'2': {
                if (!obj.Empty()) {
                    obj.Title();
                    obj.show();
                    break;
                }
                cout << "Очередь пуст!!! " << endl;
                break;
            }
            case'3': {
                if (!obj.Empty()) {
                    obj.Dequeue1();
                    break;
                }
                cout << "Очередь пуст!!! " << endl;
                break;
              }
            case'4': {
                if (!obj.Empty()) {
                    result = obj.Dequeue();
                    cout << " Удаленный данные:  " << result << endl;
                }
                else cout << "  Пуст! " << endl;
                break;
            }
            case'5': {
                obj.Clear();
                break;
            }
            case'6': {
                if (!obj.Empty()) {
                    Queue<T>* elem = obj.sSearch();
                    obj.Title();
                    elem->show();
                    delete elem;
                }
                else cout << "  Пуст! " << endl;
                break;
            }
            case'7': {
                obj.Edit();
                break;
            }
            case'8': {
               
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
            default: break;
        }
        system("pause");
    } while (ch != '0');
}
