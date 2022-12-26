#include <iostream>
#include <vector>
#include "Employee Hiearchy/Employee.h"
#include "Utility/Register.h"

using namespace std;

int main()
{    
    cout << "This is the beginning of the Coldstone Application!" << endl;
    
    Time t1(1, 40, 2);
    Date d1(18, 5, 2003);

    Employee Dom("Dom", 13.00, d1, 207233498);

    Dom.ClockIn(t1);
    return 0;
}