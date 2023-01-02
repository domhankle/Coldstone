#include "Employee.h"
#include "DynamicMemory.h"

Employee::Employee()
    : name(" "), payRate(0.0), dateOfBirth(Date()), clockedIn(false), socialSecurityNumber(000000000),
      registerInUse(nullptr), currentTimeCard(nullptr)
{}

Employee::Employee(string aName, float aPayRate, Date aDate, int aSocialSecurityNum)
    : name(aName), payRate(aPayRate), dateOfBirth(aDate), clockedIn(false), socialSecurityNumber(aSocialSecurityNum),
      registerInUse(nullptr), currentTimeCard(nullptr)
{}

Employee::Employee(const Employee& otherEmployee)
    : name(otherEmployee.GetName()), payRate(otherEmployee.GetPayRate()), dateOfBirth(otherEmployee.GetDateOfBirth()),
      clockedIn(otherEmployee.IsClockedIn()), socialSecurityNumber(otherEmployee.GetSocialSecurityNumber()), registerInUse(nullptr),
      currentTimeCard(nullptr)
{
    
    if(this != &otherEmployee)
    {
        if(currentTimeCard != nullptr)
        {
            delete currentTimeCard;
        }

        currentTimeCard = otherEmployee.GetTimeCardMemoryLoc() ? new TimeCard(*(otherEmployee.GetTimeCardMemoryLoc())) : nullptr;

        if(registerInUse != nullptr)
        {
            delete registerInUse;
        }

        registerInUse = otherEmployee.GetRegisterMemoryLoc() ? new Register(*(otherEmployee.GetRegisterMemoryLoc())) : nullptr;

        for(int i = 0; i < otherEmployee.GetNumRequestOffDays(); i++)
        {
            this -> requestOffDays.push_back(new Date);
            *(requestOffDays.at(i)) = *(otherEmployee.GetRequestOffDays().at(i));
        }

    }
}

Employee::~Employee()
{
    if(registerInUse != nullptr)
    {
        delete registerInUse;
        registerInUse = nullptr;
    }
    
    if(currentTimeCard != nullptr)
    {
        delete currentTimeCard;
        currentTimeCard = nullptr;
    }

    CleanPointerVector(requestOffDays);
}

TimeCard* Employee::GetTimeCardMemoryLoc() const
{
    return this -> currentTimeCard;
}

Register* Employee::GetRegisterMemoryLoc() const
{
    return this -> registerInUse;
}

string Employee::GetName() const
{
    return name;
}

float Employee::GetPayRate() const
{
    return payRate;
}

int Employee::GetSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

bool Employee::IsClockedIn() const
{
    return clockedIn;
}

string Employee::GetEmployeeCode() const
{
    return employeeCode;
}

Date Employee::GetDateOfBirth() const
{
    return dateOfBirth;
}

vector<Date*> Employee::GetRequestOffDays() const
{
    return requestOffDays;
}

int Employee::GetNumRequestOffDays() const
{
    return requestOffDays.size();
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

void Employee::SetSocialSecurityNumber(int aSocialSecurityNum)
{
    socialSecurityNumber = aSocialSecurityNum;
}

void Employee::ClockIn(Time& timeIn, Date& dateIn, Register& aRegister)
{

    registerInUse = new Register(aRegister);

    if(!IsClockedIn())
    {

        if(registerInUse -> CodeExists(this -> GetEmployeeCode()))
        {
            this -> SetClockedStatus(true);
            currentTimeCard = registerInUse -> TimeCardIn(timeIn, dateIn, this -> GetName());
        }
        else
        {
            cout << "Invalid code!" << endl;
        }
        
    }
    else
    {
        cout << "Employee is already clocked in!" << endl;
    }
}

void Employee::ClockOut(Time& timeOut, Register& aRegister)
{
    SetClockedStatus(false);
    registerInUse -> TimeCardOut(timeOut, currentTimeCard);

    aRegister = *registerInUse;

    delete registerInUse;
    delete currentTimeCard;

    registerInUse = nullptr;
    currentTimeCard = nullptr;
}

void Employee::operator=(const Employee& otherEmployee)
{
    this -> SetEmployeeCode(otherEmployee.GetEmployeeCode());
    this -> SetPayRate(otherEmployee.GetPayRate());
    this -> SetClockedStatus(otherEmployee.IsClockedIn());
    this -> SetDateOfBirth(otherEmployee.GetDateOfBirth());
    this -> SetSocialSecurityNumber(otherEmployee.GetSocialSecurityNumber());
    this -> SetName(otherEmployee.GetName());

    delete currentTimeCard;
    delete registerInUse;

    currentTimeCard = otherEmployee.GetTimeCardMemoryLoc() ? new TimeCard(*(otherEmployee.GetTimeCardMemoryLoc())) : nullptr;
    registerInUse = otherEmployee.GetRegisterMemoryLoc() ? new Register(*(otherEmployee.GetRegisterMemoryLoc())) : nullptr;

    for(int i = 0; i < otherEmployee.GetNumRequestOffDays(); i++)
    {
        this -> requestOffDays.push_back(new Date);           
        *(requestOffDays.at(i)) = *(otherEmployee.GetRequestOffDays().at(i));
    }
}