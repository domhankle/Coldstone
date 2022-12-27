#ifndef TIME_H
#define TIME_H

struct Time
{
    int second;
    int minute;
    int hour;

    Time();
    Time(int aSecond, int aMinute, int aHour);
};

#endif