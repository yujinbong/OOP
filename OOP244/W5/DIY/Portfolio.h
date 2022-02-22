/* ------------------------------------------------------
Workshop 5 part 2
Student Name : Yujin Bong
Student ID : 147525208
Section : NDD
Professor : Arezoo Tony
Date : Feb.16
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_

#include <iostream>
#include <string>

using namespace std;
namespace sdds {

    class Portfolio {
        const int MAX_VALUE = 100000;
        double m_value = 0;
        char m_stock[16];
        char m_type;

        void emptyPortfolio();

    public:
        Portfolio();

        Portfolio(double value, const char *stock, char type);

        ~Portfolio();

        void dispPortfolio() const;

        operator double() const;

        operator const char *() const;

        operator const char() const;

        operator bool() const;

        Portfolio &operator+=(double value);

        Portfolio &operator-=(double value);

        bool operator~() const;

        Portfolio &operator>>(Portfolio &right);

        Portfolio &operator<<(Portfolio &left);

        ostream &display() const;

    };


    // binary helper

    double operator+(double left, const Portfolio &right);

    double operator+=(double &left, const Portfolio &r);

}
#endif // SDDS_Portfolio_H_
