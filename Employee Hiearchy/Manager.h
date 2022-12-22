#ifndef MANAGER_H
#define MANGER_H

#include "Employee.h"
#include "../Utility/Schedule.h"
//#include "TruckOrder.h"

class Manager : Employee
{
    private:

        Schedule *workSchedule;
        //TruckOrder* currentOrder;


    public:

        Manager();
        ~Manager() override;
        //Schedule CreateSchedule();
        

    
};


#endif