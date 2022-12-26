#include "Employee.h"

Employee::Employee()
    : name(" "), payRate(0.0), dateOfBirth(Date()), clockedIn(false), socialSecurityNumber(000000000),
      registerInUse(nullptr)
{}

Employee::Employee(string aName, float aPayRate, Date aDate, int aSocialSecurityNum)
    : name(aName), payRate(aPayRate), dateOfBirth(aDate), clockedIn(false), socialSecurityNumber(aSocialSecurityNum),
      registerInUse(nullptr)
{}

Employee::~Employee()
{
    if(registerInUse != nullptr)
    {
        delete registerInUse;
        registerInUse = nullptr;
    }
}

string Employee::GetName()
{
    return name;
}

float Employee::GetPayRate()
{
    return payRate;
}

int Employee::GetSocialSecurityNumber()
{
    return socialSecurityNumber;
}

bool Employee::IsClockedIn()
{
    return clockedIn;
}

string Employee::GetEmployeeCode()
{
    return employeeCode;
}

void Employee::SetName(string aName)
{
    name = aName;
}

void Employee::SetPayRate(float aPayRate)
{
    payRate = aPayRate;
}

void Employee::SetDateOfBirth(Date aDate)
{
    dateOfBirth = aDate;
}

void Employee::SetClockedStatus(bool aClockedStatus)
{
    clockedIn = aClockedStatus;
}

void Employee::SetEmployeeCode(string aCode)
{
    employeeCode = aCode;
}

void Employee::ClockIn(Time timeIn, Register& aRegister)
{

    registerInUse = new Register(aRegister);

    if(!IsClockedIn())
    {

        if(registerInUse -> CodeExists(this -> GetEmployeeCode()))
        {
            this -> SetClockedStatus(true);
            registerInUse -> AddEmployeeCode(this -> GetEmployeeCode());
        }
        
    }
}