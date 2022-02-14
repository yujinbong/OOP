/*
    ==================================================
    Workshop3 (Part-1):
    ==================================================
    Name   : Yujin Bong
    Email  : ybong@myseneca.ca
    Section: NDD
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    void Train::set(const char *nameOftrain, int numberOfpeople, double speed)
    {
        //nullptr=="" ==>false
        if(nameOftrain!=nullptr && strlen(nameOftrain) >0 && strlen(nameOftrain)<MAX_NAME_LEN)
        {

            strcpy(m_nameOftrain,nameOftrain);
        }

        if(numberOfpeople>0 && numberOfpeople<MAX_PEOPLE)
            m_numberOfpeople=numberOfpeople;


        if(speed>0 && speed<MAX_SPEED)
            m_speed=speed;

    };
    int Train::getNumberOfPeople() const
    {
        return m_numberOfpeople;
    };
    const char* Train::getName() const
    {
        return m_nameOftrain;
    };
    double Train::getSpeed() const
    {
        return m_speed;
    };
    bool Train::isSafeEmpty() const
    {/*
    trains[0].set(nullptr, 100, 123.55); //true가 나오면  valid
	trains[1].set("", 100, 123.55);
	trains[2].set("VIA Rail Abitibi", -100, 123.45);
	trains[3].set("VIA Rail Abitibi", 100, -123.45);
	trains[4].set("VIA Rail Abitibi", 100, 5000);
	trains[5].set("Seneca Express", -1, -1);
	trains[6].set("VIA Rail Abitibi", 333, 115.95);
 */

        return (strcmp(m_nameOftrain, "Seneca Express")==0)|| m_numberOfpeople<=0 || m_speed<=0.0;
    };

    void Train::display() const
    {
        if(isSafeEmpty())
            cout << "Safe Empty State!\n";
        else
        {
            cout << "NAME OF THE TRAIN : " << m_nameOftrain << endl;
            cout << "NUMBER OF PEOPLE  : " << m_numberOfpeople << endl;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "SPEED             : " << m_speed << " km/h"<< endl;
        }
    }
}
