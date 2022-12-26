#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>
#include <string>
#include "../Date.h"
#include "../Time.h"

using namespace std;

class Register
{
    public:

        Register();
        Register(int aID);
        Register(const Register& otherRegister);

        bool CodeExists(string aCode);

        void AddEmployeeCode(string aCode);
        void AddClockInTime(Time aTime);
        void SetRegisterID(int aID);

        string GetEmployeeCode(int index) const;
        Time GetEmployeeClockInTime(int index) const;
        int GetRegisterID() const;

        void operator=(const Register& otherRegister);

    private:

        int registerID;
        vector<string> employeeCodes;
        vector<Time> employeesClockInTime;
};

inline
ostream& operator<<(ostream& out, const Register& registerObj);

#endif