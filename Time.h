#ifndef TIME_H
#define TIME_H

struct Time
{
    int second;
    int minute;
    int day;

    Time();
    Time(int aSecond, int aMinute, int aDay);
};

#endif