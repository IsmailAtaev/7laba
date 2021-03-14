#pragma once
#include "Queue.cpp"
#include "Teacher.h"
#include "Party.h"
#include "Teacher_Party.h"
#include "File.h"


template<class T>
class Interface
{
private:
    T obj;
    std::string fileN;
public:
    Interface() { }
    Interface(std::string f) { this->fileN = f; }
    ~Interface() { }
    static void menu();
    void Funck();
};