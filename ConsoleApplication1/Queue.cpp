#include "Queue.h"
#include "Party.h"
#include "Teacher.h"
#include "Teacher_Party.h"


template<typename T>
void Queue<T>::Clear() {
    if (this->Empty()) {
        cout << " Пусто!" << endl;
        return;
    }

    while (this->size != 0) {
        Dequeue1();
    }
}

template<typename T>
void Queue<T>::show() {
    if (this->Empty())
        return;
    Node<T>* temp = head;
    for (int i = 0; i < size; i++) {
        cout << "|" << setw(2) << i + 1 << "|" << temp->data << endl;
        temp = temp->prev;
    }
}

template<typename T>
Queue<T>* Queue<T>::sSearch()
{
    Queue<T>* geler = new Queue<T>();
    if (this->Empty()) {
        cout << " Очередь пуст нечего искать ! " << endl;
    }
    else {
        T ress{};
        ress.vvodSearch();
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->data == ress) {
                T www = temp->data;
                geler->Enqueue(www);
            }
            temp = temp->prev;
        }
    }
    return geler;
}

template<typename T>
void Queue<T>::Edit()
{
    if (this->Empty()) {
        cout << "\tПусто" << endl;
        return;
    }
    else {
        T perem{};
        this->show();
        cout << " Номер редактируемого элемента: "; 
        int  k ;
        cin >> k;
        if (k > this->GetSize() || k <= 0) {
            cout << " Выхад за предел " << endl;
        }
        else {
            (*this)[--k].edit();
        }
    }
}

template<typename T>
T& Queue<T>::operator[](int index) {
    Node<T>* curr = head;
    if (index >= size || index < 0)
        return curr->data;

    for (int i = 0; i < index; i++) {
        curr = curr->prev;
    }
    return curr->data;
}

template<typename T>
T& Queue<T>::Peek() {
    if (head != NULL)
        return head->data;
    else {
        return T();
        /*T* temp = nullptr;
        return *temp;*/
    }
}

template<typename T>
bool Queue<T>::Empty() {
    return size == 0;
}

template<typename T>
 int Queue<T>::GetSize() {
    return size;
}

template<typename T>
void Queue<T>::Enqueue(T& data)
{
    if (size == 0) {
        head = new Node<T>;
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
        tail = head;
        size++;
        return;
    }
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = tail;
    tail->prev = temp;
    tail = temp;
    size++;
}

template<typename T>
T Queue<T>::Dequeue()
{
    if (!(head))
        return T();

    T data = head->data;
    Node<T>* temp = head;
    head = head->prev;
    if (head)
        head->next = nullptr;
    delete temp;
    size--;
    return data;
}

template<typename T>
inline void Queue<T>::Dequeue1() {
    if (!(head))
        return;
    Node<T>* temp = head;
    if (head)
        head->next = nullptr;
    head = head->prev;
    delete temp;
    size--;
}

template<typename T>
inline Queue<T>::Queue(const Queue<T>& obj) {
    this->size = obj.size;
    this->head = obj.head;
    this->tail = obj.tail;
}
