#pragma once
#include <string>
#include <iostream>

class myExeption
{
private:
	mutable int numberCode;
public:
	myExeption(int nCode) :numberCode(nCode) { }
	~myExeption() { }
	int getNumberCod() { return this->numberCode; }
};
 
class myExeption_Inpit : public myExeption
{
private:
	std::string str;
public:
	myExeption_Inpit(int nCode = 0,std::string str = "") :myExeption(nCode) { 
		this->str = str; 
	}
	void Print() {
		std::cout <<" Код ошибки № " << this->getNumberCod() << this->str << std::endl; 
	}
	~myExeption_Inpit() { }
};
