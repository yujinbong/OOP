/*
    ==================================================
    Workshop3 (Part-1):
    ==================================================
    Name   : Yujin Bong
    Email  : ybong@myseneca.ca
    Section: NDD
*/

#ifndef W3P1_TRAIN_H
#define W3P1_TRAIN_H
//https://protect-us.mimecast.com/s/6ONcCo29XES4AL16t1VeMF?domain=github.com
#include <iostream>
namespace sdds
{
    const int MAX_NAME_LEN=20;
    const int MAX_PEOPLE=1000;
    const int MAX_SPEED=320;

    class Train {
        char m_nameOftrain[MAX_NAME_LEN]="Seneca Express";
        int m_numberOfpeople=0;
        double m_speed=0;

    public:
        void set(const char *nameOftrain, int numberOfpeople, double speed);
        int getNumberOfPeople() const;
        const char* getName() const;
        double getSpeed() const;
        bool isSafeEmpty() const;
        void display() const;
    };
}

#endif //W2P2_DNA_H

