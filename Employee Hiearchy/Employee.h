#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "../Date.h"

using namespace std;

//Employee Class
class Employee
{
    private:

        int socialSecurityNumber;

    protected:

        string name;
        float payRate;
        Date dateOfBirth;
        bool clockedIn;
    

    public:

        string GetName();
        float GetPayRate();
        int GetSocialSecurityNumber();

        void SetName(string aName);
        void SetPayRate(float aPayRate);
        void SetDateOfBirth(Date aDate);

        Employee();
        Employee(string aName, float aPayRate, Date aDate, bool clockedIn);
        virtual ~Employee();

        virtual void ClockIn(Date timeIn);
        virtual float ClockOut(Date timeOut);

};

#endif