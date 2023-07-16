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
};

/**
 * read added data to a specified file
 * 
 * @return 0 on success
*/
template<typename T>
int Filezilla<T>::read()
{
    fstream file(filePath, ios::in | ios::binary);
    if(!file) return 1;
    file.read((char*) &size, sizeof(int));
    temp.resize(size);
    file.read((char*) &temp, temp.size()*sizeof(T));
    file.close();

    dataList = temp;

    if(dataList.size() == 0) return 1;

    return 0;
};

/**
 * write added data to a specified file
 * 
 * @return 0 on success
*/
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
    dataList.push_back(data);
    !isModified ? isModified = true : continue;
    return 0;
};

template<typename T>
int Filezilla<T>::addQueue(vector<T> data)
{
    for(auto i : data)
        dataList.push_back(i);

    !isModified ? isModified = true : continue;

    return 0;
};

template<typename T>
void Filezilla<T>::setPath(string path)
{
    filePath = path;
};

template<typename T>
vector<T> Filezilla<T>::getData()
{
    return dataList;
};