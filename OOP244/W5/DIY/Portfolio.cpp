/* ------------------------------------------------------
Workshop 5 part 2
Student Name : Yujin Bong
Student ID : 147525208
Section : NDD
Professor : Arezoo Tony
Date : Feb.16
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio() {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';//default
    }

    Portfolio::Portfolio(double value, const char *stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    Portfolio::~Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char *) (*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    std::ostream &Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        } else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        } else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char *() const {
        return m_stock;
    }

    Portfolio::operator const char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' ||
                m_type == 'I');
    }

    double operator+(double left, const Portfolio &right) {
        return double(left) + double(right);
    }


    double operator+=(double &left, const Portfolio &r) {
        return left += double(r);
    }


    bool Portfolio::operator~() const {
        return m_value < 0; // less then 0
    }

    /*
        Portfolios[5] += 250005.50;
        Portfolios[4] -= 150000.50;
     */
    Portfolio &Portfolio::operator+=(double value) {
        if (value < MAX_VALUE) {
            m_value += value;
        }
        return *this;
    }

    Portfolio &Portfolio::operator-=(double value) {
        if (value < MAX_VALUE) {
            m_value -= value;
        }
        return *this;
    }


    Portfolio &Portfolio::operator>>(Portfolio &right) {

        if (operator bool()) {
            right.m_value += m_value;
        }
        emptyPortfolio();

        return *this;
    }


    Portfolio &Portfolio::operator<<(Portfolio &left) {

        if (operator bool()) {
            m_value += left.m_value;
            left.emptyPortfolio();
        }

        return *this;
    }


    double operator+=(const Portfolio &r, double &left) {
        return left += double(r);
    }


}
