#pragma once
#include <fstream>
#include <string>
using namespace::std;

template <typename T>
class MyFile
{
private:
	fstream file;
public:
	MyFile() {};
	~MyFile() { fclose(); };
	bool Open_to_read(string);
	bool Open_to_write(string);
	bool Open_to_add(string);
	void fclose();
	bool Fin(const T&);
	bool Fout(T&);
};

template<typename T>
inline bool MyFile<T>::Open_to_read(string path)
{
	file.open(path, ios_base::in);
	if (file.is_open()) return true;
	else return false;
}

template<typename T>
inline bool MyFile<T>::Open_to_write(string path)
{
	file.open(path, ios_base::out | ios_base::trunc);
	if (file.is_open()) return true;
	else return false;
};

template<typename T>
inline bool MyFile<T>::Open_to_add(string path)
{
	file.open(path, ios_base::app);
	if (file.is_open()) return true;
	else return false;
}

template<typename T>
inline void MyFile<T>::fclose()
{
	if (file.is_open())file.close();
}

template<typename T>
inline bool MyFile<T>::Fin(const T& ob)
{
	if (file << ob)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool MyFile<T>::Fout(T& ob)
{
	if (file >> ob)
	{
		return true;
	}
	else
	{
		return false;
	}
};