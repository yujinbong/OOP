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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"
using namespace std;
namespace sdds{

    void Train::set(const char *nameOftrain, int numberOfpeople, double speed)
    {      //cout << __FUNCTION__ << "set" << endl;

        //nullptr=="" ==>false
        if(nameOftrain!=nullptr && strlen(nameOftrain) >0 && strlen(nameOftrain)<MAX_NAME_LEX)
        {

            strcpy(m_nameOftrain,nameOftrain);
        }

        if(numberOfpeople>0 && numberOfpeople<MAX_PEOPLE)
            m_numberOfpeople=numberOfpeople;


        if(speed>0 && speed<MAX_SPEED)
            m_speed=speed;

    };


    /*  bool Train::isSafeEmpty() const{
          //    cout << __FUNCTION__ << "issafe" << endl;
          return (strcmp(m_nameOftrain, "")==0)|| m_numberOfpeople>MAX_PEOPLE || m_speed>MAX_SPEED && m_speed<0;
      }*/
    bool Train::isSafeEmpty() const{
        return (strcmp(m_nameOftrain, "")==0)|| m_numberOfpeople>MAX_PEOPLE || m_numberOfpeople <0|| m_speed>MAX_SPEED || m_speed<0;
    }

    bool Train::changeSpeed (double speed) {
//cout << __FUNCTION__ << "change" << endl;
        m_speed+= speed;
        if(m_speed < 0){
            m_speed=0;
            return true;
        }
        else if(m_speed>MAX_SPEED){
            m_speed=MAX_SPEED;
            return true;
        }

        return false;
    }

    void Train::loadPeople(int numberOfpeople) {
        m_numberOfpeople += numberOfpeople;
        if(m_numberOfpeople< 0)
            m_numberOfpeople= 0.0;
        if(m_numberOfpeople > MAX_PEOPLE)
            m_numberOfpeople = MAX_PEOPLE;
    }

    int transfer(Train &t1,Train &t2){ //글로벌 함수일때,

        // if(t1.getNumberOfPeople()== -1 || t2.getNumberOfPeople() == -1)
        if(t1.m_numberOfpeople == -1 || t2.m_numberOfpeople == -1){
            return -1;}
        if(t2.m_numberOfpeople > 0){
            t1.m_numberOfpeople += t2.m_numberOfpeople;
            if(t1.m_numberOfpeople >MAX_PEOPLE){
                t2.m_numberOfpeople = t1.m_numberOfpeople % MAX_PEOPLE;

                t1.m_numberOfpeople -= t2.m_numberOfpeople;

            }
        }

return -1;
    }





    int Train::getNumberOfPeople() const
    {
        return m_numberOfpeople; //> 0 && m_numberOfpeople <MAX_PEOPLE;
    };
    const char* Train::getName() const
    {
        return m_nameOftrain;
    };
    double Train::getSpeed() const
    {
        return m_speed;
    };


    Train & Train::operator=(Train & t2){

        strcpy(m_nameOftrain,t2.m_nameOftrain);
        m_numberOfpeople = t2.m_numberOfpeople;
        m_speed=t2.m_speed;
        return *this;
    }


    void Train::display() const {
        // cout << __FUNCTION__ << "display" << endl;
        if (isSafeEmpty())
            cout << "Safe Empty State!\n";
        else {
            cout << fixed << setprecision(2);
            cout << "NAME OF THE TRAIN : " << m_nameOftrain << endl;
            cout << "NUMBER OF PEOPLE  : " << m_numberOfpeople << endl;
            cout << "SPEED             : " << m_speed << " km/h" << endl;
        };


    }
}
