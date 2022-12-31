#include <iostream>
#include <vector>
#include "Employee.h"
#include "Time.h"
#include "Register.h"
#include "Schedule.h"

using namespace std;

int main()
{   

   vector<Employee*> empVector;
    Date* currentSchedule = new Date[7];

    for(int i = 0; i < 7; i++)
    {
        currentSchedule[i].day = i+1;
        currentSchedule[i].month = 5;
        currentSchedule[i].year = 2022;
    }

    Employee* employee1 = new Employee("Dom", 13, Date(0, 0, 0), 01000203);
    Employee* employee2 = new Employee("James", 12, Date(0, 0, 0), 01000203);
    Employee* employee3 = new Employee("Abigail", 15, Date(0, 0, 0), 01002003);

    empVector.push_back(employee1);
    empVector.push_back(employee2);
    empVector.push_back(employee3);

    Schedule schedule1;

    schedule1.SetDays(currentSchedule);
    schedule1.SetEmployees(empVector);
    

    cout << schedule1; 

    return 0;
}