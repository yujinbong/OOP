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

#ifndef W8_SHAPE_H
#define W8_SHAPE_H

#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
    class Shape {
    public:
        virtual void draw(ostream &os) const = 0;// pure virtual function
        virtual void getSpecs(istream &is) = 0;
        virtual ~Shape(); // what is the virtual empty destructor?

    };

    //Shape helper functions
    ostream &operator<<(ostream &os, const Shape &s);
    istream &operator>>(istream &is, Shape &s);
}

#endif //W8_SHAPE_H
