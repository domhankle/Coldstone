#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

//Employee Class
class Employee
{
    private:



    protected:

        string name;
        float payRate;


    public:

        string GetName();
        float GetPayRate();

        void SetName(string aName);
        void SetPayRate(float aPayRate);

        Employee();
        Employee(string aName, float aPayRate);
        virtual ~Employee();

};

#endif