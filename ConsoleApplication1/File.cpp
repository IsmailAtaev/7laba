#include "File.h"

/*template<class T>
std::fstream operator<<(std::fstream& fout, T& objFout)
{
	fout << objFout;
	return fout;
}

template<class T>
std::fstream operator>>(std::fstream& fin, T& objFin)
{
	fin >> objFin;
	return objFin;
}

*/


std::string File::getFileName() const
{
	return this->fileName;
}
