#pragma once
#include<iostream>
using namespace std;

class TDate
{
private:
    int year;  //xxxx
    int month;  //1-12
    int day;  //1-31
public:
    TDate(int year,int month,int day);
    ~TDate();
    friend std::ostream& operator<<(std::ostream& os,const TDate& td);
};

TDate::TDate(int year,int month,int day):year(year),month(month),day(day){
}


TDate::~TDate()
{
}

std::ostream& operator<<(std::ostream& os,const TDate& td)
{
    os<<td.year<<"年"<<td.month<<"月"<<td.day<<"日";
    return os;
}
