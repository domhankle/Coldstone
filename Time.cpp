#include "Time.h"

Time::Time()
    : second(0), minute(0), hour(0)
{

}

Time::Time(int aSecond, int aMinute, int aHour)
    : second(aSecond), minute(aMinute), hour(aHour)
{
    
}

TimeCard::TimeCard()
    : name(""), timeIn(Time(0, 0, 0)), timeOut(Time(0, 0, 0)), dateOfTimeCard(Date(0, 0, 0))
{

}

TimeCard::TimeCard(string aName,Time t1, Time t2, Date aDate)
    : name(aName), timeIn(t1), timeOut(t2), dateOfTimeCard(aDate)
{

}


TimeCard::TimeCard(const TimeCard& otherTimeCard)
    : name(otherTimeCard.name), timeIn(otherTimeCard.timeIn), timeOut(otherTimeCard.timeOut),
      dateOfTimeCard(otherTimeCard.dateOfTimeCard)
{

}