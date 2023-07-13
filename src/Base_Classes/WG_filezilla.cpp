#include <vector>
#include <fstream>

#include "WG_filezilla.h"

using std::vector;
using std::fstream;
using std::ios;
using std::to_string;


template<typename T>
Filezilla<T>::Filezilla()
{
    size = 0;
    isModified = false;
    filePath = "";
};

template<typename T>
int Filezilla<T>::read()
{
    fstream file(filePath, ios::in | ios::binary);
    file.read((char*) &size, sizeof(int));
    temp.resize(4);
    file.read((char*) &temp, temp.size()*sizeof(T));
    file.close();

    dataList = temp;

    return 0;
};

template<typename T>
int Filezilla<T>::write()
{
    fstream file(filePath, ios::out | ios::binary);
    if(file.fail()) return -1;
    size = dataList.size(); 
    file.write((char*) &size, sizeof(int));
    file.write((char*) &dataList, dataList.size()*sizeof(T));
    file.close();
    dataList.clear();
    return 0;
};

template<typename T>
int Filezilla<T>::add( T data)
{
    try{
        dataList.push_back(data);
    }catch(...) {
        return -1;
    }

    return 0;
};

template<typename T>
int Filezilla<T>::addQueue(vector<T>* data)
{
    try
    {
        for(auto i : *data)
            dataList.push_back(i);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
};

template<typename T>
void Filezilla<T>::setPath(string path)
{
    filePath = path;
};

template<typename T>
vector<T> Filezilla<T>::getVal()
{
    return dataList;
};