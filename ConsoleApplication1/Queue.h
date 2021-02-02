#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
};

template<typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue() : head(NULL), tail(NULL), size(0) {}
    ~Queue() { this->Clear(); }
    Queue(const Queue<T>& obj);
    void Enqueue(T& data);
    T Dequeue();
    void Dequeue1();
    void Clear();
    int GetSize();
    bool Empty();
    T& Peek();
    T& operator[](int index);
    void show();
    Queue<T>* sSearch();
    void Edit();
    static void Title() {
        T tit;
        tit.title();
    }
};