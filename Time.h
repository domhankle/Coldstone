#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

struct Time
{
    int second;
    int minute;
    int hour;

    Time();
    Time(int aSecond, int aMinute, int aHour);
};

inline
ostream& operator<<(ostream& out, const Time& timeObj)
{
    out << timeObj.hour << ":" << timeObj.minute << ":" << timeObj.second;

    return out;
}

struct TimeCard
{
    Date dateOfTimeCard;
    Time timeIn;
    Time timeOut;

    string name;

    TimeCard(const TimeCard& otherTimeCard);
    TimeCard();
    TimeCard(string aName, Time t1, Time t2, Date aDate);
};

inline
ostream& operator<<(ostream& out, const TimeCard& timeCardObj)
{
    out << "Name: " << timeCardObj.name << endl
        << "Date: " << timeCardObj.dateOfTimeCard << endl
        << timeCardObj.timeIn << " - " << timeCardObj.timeOut;

    return out;
}

#endif