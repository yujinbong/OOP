/* ------------------------------------------------------
Workshop 10 part 1
 //name: Yujin Bong
//SECTION : NCC
//PROFESSOR : Arezoo.tony
Module: N/A
Filename: temps.h
Version 1
Author: Fardad Soleimanloo  22/04/12
Revision History
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

#ifndef UNTITLED_TEMPS_H
#define UNTITLED_TEMPS_H

#include <iostream>
#include <cstring>
#include "Collection.h"
#include "Student.h"
#include "Employee.h"
#include "Car.h"
#include "Displayable.h"
using namespace std;
namespace sdds {
    template<typename T>

    Collection <T> select(const T array[], int size, const T &b) {

        int count = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == b) {
                count++;
            }
        }
       
        Collection<T> collection(count);
        int c=0;
        for (int i = 0; i < size; i++) {
            if (array[i] == b) {
                collection[c]=array[i];
                //cout <<  collection[count] << endl;
                c++;
            }

        }
        return collection;
    }
    template<typename T>
    void printCollection(const Collection<T> &s,const char *C) {
        //cout <<  "printCollection:" << s.size() << endl;
        cout << C << endl;
        for (int i = 0; i < s.size(); i++) {
            cout << s[i]<<endl;
        }
    }
}

#endif //UNTITLED_TEMPS_H

