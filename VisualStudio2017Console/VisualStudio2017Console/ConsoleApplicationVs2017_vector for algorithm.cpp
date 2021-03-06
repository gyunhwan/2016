// ConsoleApplicationVs2017.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

class KData
{
private:
    char*   buffer;
    int     iData;

public:
    static int iConstructor;
    static int iCopyConstructor;
    static int iMoveConstructor;
    static int iDestructor;

public:
    KData( int d_=0)
    {
        std::cout << "constructor" << std::endl;
        iData = d_;
        ++iConstructor;
        buffer = new char[100];
    }
    KData(const KData& rhs_)
    {
        std::cout << "copy constructor" << std::endl;
        ++iCopyConstructor;
        buffer = new char[100];
        memcpy(buffer, rhs_.buffer, sizeof(char) * 100);
    }
    KData( KData&& rhs_)
    {
        std::cout << "move constructor" << std::endl;
        ++iMoveConstructor;
        buffer = rhs_.buffer;
        rhs_.buffer = nullptr;
    }
    ~KData()
    {
        std::cout << "destructor" << std::endl;
        ++iDestructor;
        delete[] buffer;
        buffer = nullptr;
    }
    void SetInt(int d_)
    {
        iData = d_;
    }
    bool operator==(const KData& rhs_) const
    {
        return false;
    }
    bool operator<(const KData& rhs_) const
    {
        return false;
    }
};

int KData::iConstructor = 0;
int KData::iCopyConstructor = 0;
int KData::iMoveConstructor = 0;
int KData::iDestructor = 0;

template<typename T, typename U>
bool myfind(T _first, T _last, const U& _value)
{
    while (_first != _last)
    {
        if (*_first == _value)
            return true;
        ++_last;
    }
    return false;
}

int main()
{
    {
        std::vector<KData>  v;
        v.reserve(100);
        for (int i = 0; i < 100; ++i)
        {
            //KData d;
            //d.SetInt(i);
            v.push_back( KData(i) );
        }
    }

    std::cout << KData::iConstructor << std::endl;
    std::cout << KData::iCopyConstructor << std::endl;
    std::cout << KData::iMoveConstructor << std::endl;
    std::cout << KData::iDestructor << std::endl;

    //KData d2;
    //d2.SetInt(3);
    //myfind(v.begin(), v.end(), d2);
    //std::find(v.begin(), v.end(), d2);
    //std::sort(v.begin(), v.end());
    return 0;
}

