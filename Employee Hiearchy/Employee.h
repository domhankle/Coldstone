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
        Date dateOfBirth;
        float payRate;


    public:

        string GetName();
        float GetPayRate();
        int GetSocialSecurityNumber();

        void SetName(string aName);
        void SetPayRate(float aPayRate);
        void SetDateOfBirth(Date aDate);

        Employee();
        Employee(string aName, float aPayRate, Date aDate);
        virtual ~Employee();

};

#endif