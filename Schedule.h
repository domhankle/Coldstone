#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Employee.h"
#include "Date.h"
#include <vector>

const static int DAYS_IN_WEEK = 7;

class Schedule
{
    private:

        vector<Employee*> employees;

    public:

        Date *days;

        Schedule();
        Schedule(Date*& aSetOfDays, vector<Employee*> aSetOfEmployees);
        ~Schedule();

        void SetDays(Date*& SetOfDays);
        void SetEmployees(vector<Employee*> aSetOfEmployees);
        
        //Employee* GetEmployeesOnSchedule() const;
        //Date* GetDatesOnSchedule() const;

        //Schedule(const Schedule& otherSchedule);

        //void operator=(const Schedule& otherSchedule);

};

//inline
//ostream& operator<<(ostream& out, const Schedule& aSchedule);

#endif