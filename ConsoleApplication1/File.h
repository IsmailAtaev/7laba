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
	std::fstream file_strema;
public:
	File(std::string nmFl = "") { this->fileName = nmFl; }
	std::string getFileName()const;
	~File(){ };
};

template <class T>
class FileTXT : public File
{
	std::ifstream inFile;
	std::ofstream outFile;
public:
	FileTXT(std::string tempFile = "") :File(tempFile)
	{
		this->file_strema.open(this->getFileName(), std::ios::in | std::ios::out);
		/*this->inFile.open(this->getFileName(), std::ios::in);
		this->outFile.open(this->getFileName(), std::ios::out);*/
	}
	~FileTXT();
	void readRrcordInFile(T& objR);
	void writeRecordInFile(T& objW);
	bool REndFile();
};

template<class T>
inline FileTXT<T>::~FileTXT()
{
	this->inFile.close();
	this->outFile.close();
}

template<class T>
inline void FileTXT<T>::readRrcordInFile(T& objR)
{
	
	if (!this->file_strema.is_open()) {
		std::cout << " file for read is not open \n ";
		return;
	}
	file_strema >> objR;
	/*std::ifstream infile(this->getFileName());
	while (infile >> objR)
	{
		if (infile.eof())
			break;
		else
		{
			std::cout << objR << std::endl;
		}
	}
	infile.close();*/
}

template<class T>
inline void FileTXT<T>::writeRecordInFile(T& objW)
{

	if (!this->file_strema.is_open()) {
		std::cout << " file for write is not open \n ";
		return;
	}
	file_strema << objW;

	/*int flag = 0;
	std::ofstream outfile(this->getFileName(), std::ios::out);
	if (!outfile.eof()) {
		std::cout << " Файл не окрыт " << std::endl;
		std::exit(1);
	}

	do {
		rewind(stdin);
		std::cin >> objW;
		outfile << objW;
		rewind(stdin);
		std::cout << " Хотите повторить  если \n нажмите ДА(1) \n нажмите НЕТ(0)" << std::endl;
		flag = input_INT(std::cin, 0, 1);
	} while (flag);
	outfile.close();*/

}


/*

template<class T>
inline void FileTXT<T>::readRrcordInFile_fstream(T& objR)
{
	

	fileName >> objR;

}

template<class T>
inline void FileTXT<T>::writeRecordInFile_fstream(T& objW)
{
	file_strema << objW;
}*/


template<class T>
inline bool FileTXT<T>::REndFile()
{
	return this->file_strema.eof();
}