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


#include "LblShape.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

    LblShape::LblShape()
    {
        m_label=nullptr;
    }

    LblShape::LblShape(const char *label)
    {
        if(label==nullptr)
            return ;
        m_label= new char[strlen(label)+1];
        strcpy(m_label,label);
    }

    LblShape::LblShape(LblShape &ls)
    {
        m_label= new char[strlen(ls.m_label)+1];
        strcpy(m_label,ls.m_label);
    }

    LblShape &LblShape::operator =(LblShape &ls)
    {
        delete [] m_label;
        m_label= new char[strlen(ls.m_label)+1];
        strcpy(m_label,ls.m_label);
        return *this;
    }

    void LblShape::getSpecs(istream &is)
    {
        char label[256];
        is.getline(label, 256, ',');
        delete [] m_label;
        m_label= new char[strlen(label)+1];
        strcpy(m_label,label);
    }

    LblShape::~LblShape()
    {
        delete [] m_label;
    }

}
