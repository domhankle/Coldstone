#include "Register.h"

Register::Register()
    : registerID(000)
{}

Register::Register(int aID)
    : registerID(aID)
{}

Register::Register(const Register& otherRegister)
{
    for(int i = 0; i < otherRegister.employeeCodes.size(); i++)
    {
        this -> AddEmployeeCode(otherRegister.GetEmployeeCode(i));
    }

    for(int i = 0; i < otherRegister.employeesClockInTime.size(); i++)
    {
        this -> AddClockInTime(otherRegister.GetEmployeeClockInTime(i));
    }

    this -> SetRegisterID(otherRegister.GetRegisterID());

}

Time Register::GetEmployeeClockInTime(int index) const
{
    return employeesClockInTime.at(index);
}

string Register::GetEmployeeCode(int index) const
{
    return employeeCodes.at(index);
}

int Register::GetRegisterID() const
{
    return registerID;
}

void Register::AddClockInTime(Time aTime)
{
    employeesClockInTime.push_back(aTime);
}

void Register::AddEmployeeCode(string aCode)
{
    employeeCodes.push_back(aCode);
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
    for(int i = 0; i < otherRegister.employeeCodes.size(); i++)
    {
        this -> AddEmployeeCode(otherRegister.GetEmployeeCode(i));
    }

    for(int i = 0; i < otherRegister.employeesClockInTime.size(); i++)
    {
        this -> AddClockInTime(otherRegister.GetEmployeeClockInTime(i));
    }

    this -> SetRegisterID(otherRegister.GetRegisterID());

}

ostream& operator<<(ostream& out, const Register& registerObj)
{
    out << "Register ID: " << registerObj.GetRegisterID() << '\n'
        << 
}