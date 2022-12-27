#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
#include "Register.h"

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
        string employeeCode;

        Register *registerInUse;    

    public:

        string GetName() const;
        float GetPayRate() const;
        int GetSocialSecurityNumber() const;
        bool IsClockedIn() const;
        string GetEmployeeCode() const;

        void SetName(string aName);
        void SetPayRate(float aPayRate);
        void SetDateOfBirth(Date aDate);
        void SetClockedStatus(bool aClockedStatus);
        void SetEmployeeCode(string aCode);

        Employee();
        Employee(string aName, float aPayRate, Date aDate, int aSocialSecurityNum);
        virtual ~Employee();

        //Employee(const Employee& otherEmployee);

        //void operator=(const Employee& otherEmployee);

        virtual void ClockIn(Time timeIn, Register& aRegister);
        //virtual float ClockOut(Time timeOut);

};

inline
ostream& operator<<(ostream& out, const Employee& employeeObj)
{
    out << "Name: " << employeeObj.GetName() << '\n'
        << "Employee Code: " << employeeObj.GetEmployeeCode() << '\n';

    return out;
}

#endif