#if !defined(_FILEZILLA_H_)
#define _FILEZILLA_H_

#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

template<typename T>
class Filezilla
{
    bool isModified;
    string filePath;
    int size;
    vector<T> dataList;
    vector<T> temp;

    public:
        Filezilla();
        int write(void);
        int read();
        int add(T data);
        int addQueue(vector<T> data);
        void setPath(string path);
        vector<T> getData();
        bool checkIsModified();
};

#endif // _FILEZILLA_H_
