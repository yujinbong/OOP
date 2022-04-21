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

#include "Shape.h"
#include <iostream>
using namespace std;
namespace sdds {

    Shape::~Shape()
    {

    }

    ostream &operator<<(ostream &os, const Shape &s)
    {
        s.draw(os);
        return os;
    }
    istream &operator>>(istream &is, Shape &s)
    {
        s.getSpecs(is);
        return is;
    }
}
