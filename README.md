# Coldstone

An application that simulates the day to day activities of a Coldstone employee.

# CPP Files

## Main

### main.cpp

Core of the application and runs the loop that questions the users on which activities they'd like to interact with.

## Utility CPPs

### Date.cpp

Defines the following:

Date::Date();
Date::Date(int aDay, int aMonth, int aYear);
void Date::operator=(const Date& otherDate);

### Time.cpp

Defines the following: 

Time();
Time(int aSecond, int aMinute, int aHour);

TimeCard(const TimeCard& otherTimeCard);
TimeCard();
TimeCard(string aName, Time t1, Time t2, Date aDate);

## Store Functionality CPPs

### Register.cpp

Defines the following:

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

## Employee Hiearchy CPPs

### Employee.cpp

Defines the following:

string GetName() const;
float GetPayRate() const;
int GetSocialSecurityNumber() const;
bool IsClockedIn() const;
string GetEmployeeCode() const;
Date GetDateOfBirth() const;

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

# Header Files

## Utility Headers

### Date.h

A struct that will be used to create instances of days that employees will work, used for scheduling, determining tasks, etc.

### Time.h

A struct that will be used to create instances of times that employees will work, used for tasks, etc. The Time.h headerfile also includes the TimeCard struct which will be used to represent instances of proof that employees have worked a certain amount of time. 


## Store Functionality Headers

### Schedule.h

A class used for determining days that employees will work.

### Register.h

A class used for simulating any register like functionality. This will include the likes of clocking in and out, ringing up a customer, etc.

## Employee Hiearchy Headers

### Employee.h

Parent class of the employee hiearchy. Holds functionality for the employees name, pay rate, date of birth, and social security number.

### Manager.h

Child class of Employee class. Holds functionality for manager position which includes creating the work schedule and putting in the truck order. 

### ShiftLeader.h

Child class of Employee class. Holds functionality for the shift leader position.

### CrewMember.h

Child class of Employee class. Holds functionality for the crewmember position.

### Trainee.h

Child class of Trainee class. Holds functionality for the trainee position.