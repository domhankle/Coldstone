#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Employee.h"
#include "Date.h"
#include "DynamicMemory.h"
#include <vector>
#include <iomanip>

const static int DAYS_IN_WEEK = 7;

class Schedule
{
    private:

        vector<Employee*> employees;
        Date *days;

    public:

        Schedule();
        Schedule(Date*& aSetOfDays, vector<Employee*> aSetOfEmployees);
        ~Schedule();

        void SetDays(Date*& SetOfDays);
        void SetEmployees(vector<Employee*> aSetOfEmployeePtrs);

        vector<Employee*> GetEmployeesOnSchedule() const;
        Date* GetDatesOnSchedule() const; 



        //Schedule(const Schedule& otherSchedule);

        //void operator=(const Schedule& otherSchedule);

};

inline
ostream& operator<<(ostream& out, const Schedule& scheduleObj)
{

    out << "Schedule for " << scheduleObj.GetDatesOnSchedule()[0] << " - " << scheduleObj.GetDatesOnSchedule()[6] << endl << endl;

    for(int i = 0; i < DAYS_IN_WEEK; i++)
    {
        if(i != 0)
        {
            out << "   |   " << scheduleObj.GetDatesOnSchedule()[i];
        }
        else
        {
            out << "|   " << scheduleObj.GetDatesOnSchedule()[i];
        }
    }

    //14 chars

    out << "   |" << endl;

    for(int i = 0; i < DAYS_IN_WEEK; i++)
    {
        out << setw(14) << "|" << scheduleObj.GetEmployeesOnSchedule().at(i) -> GetName() << "|";
    }

    return out;
}

#endif