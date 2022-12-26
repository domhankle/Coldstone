#include "Date.h"

Date::Date()
    : day(0), month(0), year(0)
{}

Date::Date(int aDay, int aMonth, int aYear)
    : day(aDay), month(aMonth), year(aYear)
{}

void Date::operator=(const Date& otherDate)
{
    this -> day = otherDate.day;
    this -> month = otherDate.month;
    this -> year = otherDate.year;
}