#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date();
    Date(int aDay, int aMonth, int aYear);

    void operator=(const Date& otherDate);
};

inline
ostream& operator<<(ostream& out, const Date& dateObj)
{
    out << dateObj.month << "/" << dateObj.day << "/" << dateObj.year;

    return out;
}



#endif