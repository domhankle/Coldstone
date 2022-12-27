#include <iostream>
#include <vector>
#include "Employee Hiearchy/Employee.h"
#include "Utility"

using namespace std;

int main()
{    
    
    Time t1(1, 40, 2);
    Date d1(18, 5, 2003);

    Employee Dom("Dom", 13.00, d1, 207233498);
    Register register1(1);


    cout << register1;



    return 0;
}