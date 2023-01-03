#include "Schedule.h"
#include "DynamicMemory.h"

Schedule::Schedule()
    : days(new Date[DAYS_IN_WEEK])
{}

Schedule::Schedule(Date*& aSetOfDays, vector<Employee*> aSetOfEmployees)
    : days (new Date[DAYS_IN_WEEK])
{
    for(int i = 0; i < DAYS_IN_WEEK; i++)
    {
        days[i] = aSetOfDays[i];
    }

    for(int i = 0; i < aSetOfEmployees.size(); i++)
    {
        employees.at(i) = new Employee();
        *(employees.at(i)) = *(aSetOfEmployees.at(i));
    }
}

Schedule::~Schedule()
{
    if(days != nullptr)
    {
        delete [] days;
        days = nullptr;
    }

    for(int i = 0; i < employees.size(); i++)
    {
        delete employees.at(i);
        employees.at(i) = nullptr;
    }

}

void Schedule::SetDays(Date*& aSetOfDays)
{
    if(days != nullptr)
    {
        delete days;
        days = nullptr;
    }

    days = new Date[7];

    for(int i = 0; i < DAYS_IN_WEEK; i++)
    {
        days[i] = aSetOfDays[i];
    }
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


