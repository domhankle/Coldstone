#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
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
        TimeCard *currentTimeCard;  
        
        vector<Date*> requestOffDays;

    public:
        string GetName() const;
        float GetPayRate() const;
        int GetSocialSecurityNumber() const;
        bool IsClockedIn() const;
        string GetEmployeeCode() const;
        Date GetDateOfBirth() const;
        vector<Date*> GetRequestOffDays() const;
        int GetNumRequestOffDays() const;

        TimeCard* GetTimeCardMemoryLoc() const;
        Register* GetRegisterMemoryLoc() const;

        void SetName(string aName);
        void SetPayRate(float aPayRate);
        void SetDateOfBirth(Date aDate);
        void SetClockedStatus(bool aClockedStatus);
        void SetEmployeeCode(string aCode);
        void SetSocialSecurityNumber(int aSocialSecurityNum);

        Employee();
        Employee(string aName, float aPayRate, Date aDate, int aSocialSecurityNum);
        virtual ~Employee();
        Employee(const Employee& otherEmployee);

        void operator=(const Employee& otherEmployee);

        virtual void ClockIn(Time& timeIn, Date& dateIn, Register& aRegister);
        virtual void ClockOut(Time& timeOut, Register& aRegister);

};

inline
ostream& operator<<(ostream& out, const Employee& employeeObj)
{
    out << "Name: " << employeeObj.GetName() << endl
        << "Employee Code: " << employeeObj.GetEmployeeCode() << endl
        << "Pay (Hourly): " << employeeObj.GetPayRate() << endl
        << "Date of Birth: " << employeeObj.GetDateOfBirth() << endl;

    return out;
}

#endif