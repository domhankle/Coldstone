#include "Register.h"

Register::Register()
    : registerID(000)
{}

Register::Register(int aID)
    : registerID(aID)
{}

Register::Register(const Register& otherRegister)
    : registerID(otherRegister.GetRegisterID())
{

    if(this != &otherRegister)
    {
        TimeCard *card = nullptr;

        employeeCodes.clear();
        employeeNames.clear();
        workHoursRecord.clear();

        for(int i = 0; i < otherRegister.GetNumEmployees(); i++)
        {
            this -> AddEmployeeCode(otherRegister.GetEmployeeCode(i), otherRegister.GetEmployeeName(i));
        }

        for(int i = 0; i < otherRegister.GetNumTimeCards(); i++)
        {
            card = new TimeCard(otherRegister.GetTimeCard(i));
            this -> AddTimeCard(card);
        }

    }
}

Register::~Register()
{
    for(int i = 0; i < this -> GetNumTimeCards(); i++)
    {
        delete this -> workHoursRecord.at(i);
        this -> workHoursRecord.at(i) = nullptr;
    }
}


string Register::GetEmployeeCode(int index) const
{
    return employeeCodes.at(index);
}

string Register::GetEmployeeName(int index) const
{
    return employeeNames.at(index);
}

TimeCard Register::GetTimeCard(int index) const
{
    return *(workHoursRecord.at(index));
}

int Register::GetRegisterID() const
{
    return registerID;
}

int Register::GetNumCodesOnFile() const
{
    return employeeCodes.size();
}

int Register::GetNumEmployees() const
{
    return employeeNames.size();
}

int Register::GetNumTimeCards() const
{
    return workHoursRecord.size();
}

void Register::AddTimeCard(TimeCard* aTimeCard)
{
    workHoursRecord.push_back(aTimeCard);
}


void Register::AddEmployeeCode(string aCode, string employeeName)
{
    employeeCodes.push_back(aCode);
    employeeNames.push_back(employeeName);
}

TimeCard* Register::TimeCardIn(Time& aTime, Date& aDate, string employeeName)
{
    TimeCard *card =  new TimeCard();

    card -> name = employeeName;
    card -> timeIn = aTime;
    card -> timeOut = Time(0, 0, 0);
    card -> dateOfTimeCard = aDate;

    this -> AddTimeCard(card);


    return card;
}

void Register::TimeCardOut(Time& aTime, TimeCard*& aTimeCardPtr)
{
    aTimeCardPtr -> timeOut = aTime;

}

void Register::RemoveEmployeeCode(string aCode)
{
    vector<string>::iterator it1 = employeeCodes.begin();
    vector<string>::iterator it2 = employeeNames.begin();

    for(int i = 0; i < employeeCodes.size(); i++)
    {
        if(aCode == employeeCodes.at(i))
        {
            employeeCodes.erase(it1);
            employeeNames.erase(it2);
            break;
        }
        it1++;
        it2++;
    }
}

void Register::SetRegisterID(int aID)
{
    registerID = aID;
}

bool Register::CodeExists(string aCode)
{
    for(int i = 0; i < employeeCodes.size(); i++)
    {
        if(aCode == employeeCodes.at(i))
        {
            return true;
        }
    }

    return false;
}

void Register::operator=(const Register& otherRegister)
{
    TimeCard *card = nullptr;

    employeeCodes.clear();
    employeeNames.clear();
    workHoursRecord.clear();

    for(int i = 0; i < otherRegister.GetNumEmployees(); i++)
    {
        this -> AddEmployeeCode(otherRegister.GetEmployeeCode(i), otherRegister.GetEmployeeName(i));
        cerr << "Loop run # " << i << endl;
    }

    for(int i = 0; i < otherRegister.GetNumTimeCards(); i++)
    {
        card = new TimeCard(otherRegister.GetTimeCard(i));
        this -> AddTimeCard(card);
    }
    this -> SetRegisterID(otherRegister.GetRegisterID());

}
