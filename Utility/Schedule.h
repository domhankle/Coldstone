#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "../Date.h"
#include "../Employee Hiearchy/Employee.h"

const int DAYS_IN_WEEK = 7;

class Schedule
{
    private:

        Date *days;
        Employee *employees;

    public:

        void SetDays(Date *setOfDays);
        void SetEmployees(Employee *setOfEmployees);
        
        Employee GetEmployee();
        int GetNumEmployees();
        Date GetDate(int index);

        Schedule();
        Schedule(Date *aSetOfDays, Employee *aSetOfEmployees);
        ~Schedule();

        Schedule(const Schedule& otherSchedule);

        void operator=(const Schedule& otherSchedule);

};

inline
ostream& operator<<(ostream& out, const Schedule& aSchedule);

#endif