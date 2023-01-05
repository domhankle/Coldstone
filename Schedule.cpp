#include "Schedule.h"

Schedule::Schedule()
    : days(new Date[DAYS_IN_WEEK])
{}

Schedule::Schedule(Date*& aSetOfDays, vector<Employee*> aSetOfEmployees)
    : days (new Date[DAYS_IN_WEEK])
{
    DeepCopyDynamicArray(aSetOfDays, this -> GetDatesOnSchedule(), DAYS_IN_WEEK);
    DeepCopyPointerVector(aSetOfEmployees, this -> GetEmployeesOnSchedule());
}

Schedule::~Schedule()
{
    CleanDynamicArray(this -> GetDatesOnSchedule(), DAYS_IN_WEEK);
    CleanPointerVector(this -> GetEmployeesOnSchedule());

}

void Schedule::SetDays(Date*& aSetOfDays)
{
    DeepCopyDynamicArray(aSetOfDays, this -> GetDatesOnSchedule(), DAYS_IN_WEEK);
}

void Schedule::SetEmployees(vector<Employee*> aSetOfEmployeePtrs)
{
    DeepCopyPointerVector(aSetOfEmployeePtrs, this -> GetEmployeesOnSchedule());
}

vector<Employee*> Schedule::GetEmployeesOnSchedule() const
{
    return employees;
}

Date* Schedule::GetDatesOnSchedule() const
{
    return days;
}


