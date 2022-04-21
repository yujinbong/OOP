/* ------------------------------------------------------
Workshop 8 part 1
 //name: Yujin Bong
//SECTION : NCC
//PROFESSOR : Arezoo.tony
Module: N/A
Filename: main.cpp
Version 1
Author: Fardad Soleimanloo  22/03/17
Revision History
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Rectangle.h"
using namespace std;
namespace sdds {

    Rectangle::Rectangle()
    {
        m_length=0;
        m_height=0;
    }

    Rectangle::Rectangle(const char *label,int length,int height) : LblShape(label)  // 초기화 리스트
    {
        m_length=length;
        m_height=height;
    }

    void Rectangle::getSpecs(istream &is)
    {
        char buf[256];
        LblShape::getSpecs(is);
        is.getline(buf, 256, ',');
        m_length = atoi(buf);
        is >> m_height;

        is.ignore(256, '\n');
    }

    void Rectangle::draw(ostream &os)const
    {
        if (m_label == nullptr)
            return;




        if (m_length <= 1 || m_height <= 1)
            return;

        os << "+";
        for (int i = 1; i < m_length-1; i++)os << "-";
        os << "+" << endl;

        os << "|" << m_label << setw(m_length - 1- strlen(m_label)) << "|" << endl;

        for (int h = 2; h < m_height - 1; h++)
        {
            os << "|";
            for (int i = 1; i < m_length - 1; i++)os << " ";
            os << "|" << endl;
        }

        os << "+";
        for (int i = 1; i < m_length - 1; i++)os << "-";
        os << "+" ;



    }

}
