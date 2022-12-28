#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class Register
{
    public:

        Register();
        Register(int aID);
        Register(const Register& otherRegister);
        ~Register();

        bool CodeExists(string aCode);
        TimeCard* TimeCardIn(Time& aTime, Date& aDate, string employeeName);
        void TimeCardOut(Time& aTime, TimeCard*& aTimeCardPtr);

        void AddEmployeeCode(string aCode, string employeeName);
        void AddTimeCard(TimeCard* aTimeCard);
        void RemoveEmployeeCode(string aCode);
        void SetRegisterID(int aID);

        string GetEmployeeCode(int index) const;
        string GetEmployeeName(int index) const;
        TimeCard GetTimeCard(int index) const;
        int GetRegisterID() const;
        int GetNumCodesOnFile() const;
        int GetNumEmployees() const;
        int GetNumTimeCards() const;
        
        void operator=(const Register& otherRegister);

    private:

        int registerID;

        vector<string> employeeCodes;
        vector<string> employeeNames;

        vector<TimeCard*> workHoursRecord;
};

inline
ostream& operator<<(ostream& out, const Register& registerObj)
{
    out << "Register ID: " << registerObj.GetRegisterID() << endl << endl
        << "============================================================" << endl
        << "EMPLOYEE CODES (" << registerObj.GetNumEmployees() << ")" << endl
        << "============================================================" << endl;

    for(int i = 0; i < registerObj.GetNumEmployees(); i++)
    {
        out << registerObj.GetEmployeeCode(i) << "---" << registerObj.GetEmployeeName(i) << endl;
    }

    out << endl
        << "=============================================================" << endl
        << "TIME CARDS ON FILE (" << registerObj.GetNumTimeCards() << ")" << endl
        << "=============================================================" << endl;

    for(int i = 0; i < registerObj.GetNumTimeCards(); i++)
    {
        out << registerObj.GetTimeCard(i) << endl;
    }
    
    
    return out;
}

#endif