# Coldstone

An application that simulates the day to day activities of a Coldstone employee.

# CPP Files

## main.cpp

Core of the application and runs the loop that questions the users on which activities they'd like to interact with.

# Header Files

## Date.h

A struct that will be used to create instances of days that employees will work, used for scheduling, determining tasks, etc.

## Time.h

A struct that will be used to create instances of times that employees will work, used for tasks, etc.

## Schedule.h

A utility class used for determining days that employees will work.

## Employee.h

Parent class of the employee hiearchy. Holds functionality for the employees name, pay rate, date of birth, and social security number.

## Manager.h

Child class of Employee class. Holds functionality for manager position which includes creating the work schedule and putting in the truck order. 

## ShiftLeader.h

Child class of Employee class. Holds functionality for the shift leader position.

## CrewMember.h

Child class of Employee class. Holds functionality for the crewmember position.

## Trainee.h

Child class of Trainee class. Holds functionality for the trainee position.