#ifndef DATE_H
#define DATE_H

struct Date
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;

    Date();
    Date(int aDay, int aMonth, int aYear);
};



#endif