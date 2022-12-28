#include <iostream>
#include <vector>
#include "Employee.h"
#include "Time.h"
#include "Register.h"
#include "Schedule.h"

using namespace std;

int main()
{   
    Schedule sched;

    Date* dates = new Date[7];

    cout << dates << endl;

    cout << *dates << endl;

    sched.SetDays(dates);

    delete dates;

    cout << *dates << endl << endl;

    cout << sched.days << endl;

    cout << *sched.days << endl;


    
    return 0;
}