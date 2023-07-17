#include <vector>
#include <fstream>

#include "WG_filezilla.h"

using std::vector;
using std::fstream;
using std::ifstream;
using std::ofstream;
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
    ifstream in(filePath, std::ios::in | std::ios::binary);
    typename vector<T>::size_type size = 0;
    in.read((char*)&size, sizeof(size));
    dataList.resize(size);
    in.read((char*)&dataList[0], dataList.size() * sizeof(T));
    in.close();
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
    ofstream out(filePath, std::ios::out | std::ios::binary);
    typename vector<T>::size_type size = dataList.size();
    out.write((char*)&size, sizeof(size));
    out.write((char*)&dataList[0], dataList.size() * sizeof(T));
    out.close();
    read();
    isModified = false;
    return 0;
};

template<typename T>
int Filezilla<T>::add( T data)
{
    dataList.push_back(data);
    isModified = true;
    return 0;
};

template<typename T>
int Filezilla<T>::addQueue(vector<T> data)
{
    for(auto i : data)
        dataList.push_back(i);

    isModified = true;

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

template<typename T>
bool Filezilla<T>::checkIsModified()
{
    return isModified;
};