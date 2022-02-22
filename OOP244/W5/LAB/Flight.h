/* ------------------------------------------------------
Workshop 5 part 1
 Student Name : Yujin Bong
Student ID : 147525208
Section : NDD
Professor : Arezoo Tony
Date : Feb.15
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H

#include <iostream>

using namespace std;

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;
    const int UnitFuel = 600; // liter/person

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];


        void emptyPlane();

    public:
        Flight();


        Flight(int passengers, double fuel, const char *title);

        ~Flight();

        ostream &display() const;

        operator int() const;

        operator double() const;

        //Unary member operator -
        operator bool() const;

        operator const char *() const;

        bool operator~() const;


        //Binary member operators
        bool operator==(const Flight &right) const;

        Flight &operator=(const Flight &right);

        Flight &operator=(int passengers);

        Flight &operator=(double fuel);

        Flight &operator+=(double fuel);

        Flight &operator+=(int passengers);

        Flight &operator-=(double fuel);

        Flight &operator-=(int passengers);

        Flight &operator>>(Flight &right);

    };

    //Binary helper
    int operator+(int left, const Flight &right);

    int operator+=(int &left, const Flight &right);

}
#endif // SDDS_FLIGHT_H
