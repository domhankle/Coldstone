#ifndef DATE_H
#define DATE_H

#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    Date();
    Date(int aDay, int aMonth, int aYear);

    void operator=(const Date& otherDate);
};



#endif