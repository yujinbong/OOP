/* ------------------------------------------------------
Workshop 3 part 2
Name: Yujin Bong
Module: N/A
Filename: Peter Liu
Version 1
Author: Peter Liu   12/29/2021
Original Author: Cornel Barna
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/


#ifndef W3P2_TRAIN_H
#define W3P2_TRAIN_H

#include <iostream>


namespace sdds {
    const double MAX_SPEED = 320.00;
    const int MAX_PEOPLE = 1000;
    const int MAX_NAME_LEX=20;


    class Train {
       // char m_nameOftrain[MAX_NAME_LEX];
        //int m_numberOfpeople;
        //double m_speed;
    public :
        char m_nameOftrain[MAX_NAME_LEX];
        int m_numberOfpeople;
        double m_speed;

        int getNumberOfPeople() const;
        const char* getName() const;
        double getSpeed() const;
        bool isSafeEmpty() const;
        void set (const char *name, int noOfPeople, double speed);
        Train & operator=(Train & );
        void display() const;
        bool changeSpeed (double speed);
        void loadPeople (int m_LoadOfPeople);

    };

    int transfer(Train& t1,Train& t2  );
}

#endif //W3P2_TRAIN_H
