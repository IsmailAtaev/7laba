#pragma once
#include <iostream>
#include <fstream>
#include "Header.h"
#include "Person.h"
#include "Teacher.h"
#include "Teacher_Party.h"



class File
{
private:
	std::string fileName;
protected:
	std::fstream file_stream;
public:
	File(std::string nmFl = "") { this->fileName = nmFl; }
	~File() { }
	std::string getFileName()const;
};





template <class T>
class FileTXT : public File
{
public:
	FileTXT(std::string tempFile = "") :File(tempFile){
		this->file_stream.open(this->getFileName(), std::ios::in | std::ios::out);
		if (!this->file_stream.is_open()) {
			std::cout << " Файл не открыт \n ";
			exit(1);
		}
	}
	~FileTXT() { this->file_stream.close(); }
	void readRecordInFile(T& objR);
	void writeRecordInFile(T& objW);
	bool REndFile();
};

template<class T>
inline void FileTXT<T>::readRecordInFile(T& objR)
{
	file_stream >> objR;
}

template<class T>
inline void FileTXT<T>::writeRecordInFile(T& objW)
{
	file_stream << objW;
}

template<class T>
inline bool FileTXT<T>::REndFile()
{
	return this->file_stream.eof();
}