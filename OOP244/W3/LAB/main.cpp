/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Filename: main.cpp
Version 1
Author: Peter Liu   12/29/2021
Original Author: Cornel Barna
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"
using namespace std;
using namespace sdds;

int main() {

    Train trains[7];

    trains[0].set(nullptr, 100, 123.55);
    trains[1].set("", 100, 123.55);
    trains[2].set("VIA Rail Abitibi", -100, 123.45);
    trains[3].set("VIA Rail Abitibi", 100, -123.45);
    trains[4].set("VIA Rail Abitibi", 100, 5000);
    trains[5].set("Seneca Express", 0, 0);
    trains[6].set("VIA Rail Abitibi", 333, 115.95);

    cout << "----------------------------------------" << endl;
    cout << "1. Testing the validation logic." << endl;
    cout << "(only trains[6] should be valid)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 7; ++i)
    {
        cout << "trains[" << i << "]: "
             << (trains[i].isSafeEmpty() ? "not valid" : "valid") << endl;
    }
    cout << "----------------------------------------" << endl << endl;

    //
    cout << "----------------------------------------" << endl;
    cout << "2. Testing the display function." << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 7; ++i)
    {
        trains[i].display();
    }
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "3. Testing the member functions." << endl;
    cout << "----------------------------------------" << endl;

    Train t1, t2;

    //t1.set(nullptr, -1, -1);
    t2.set("Bullet Train", 100, 245.95);

    cout << t1.getNumberOfPeople()
         << ','
         << t1.getName()
         << ','
         << t1.getSpeed() << endl;

    cout << t2.getNumberOfPeople()
         << ','
         << t2.getName()
         << ','
         << t2.getSpeed() << endl;
    cout << "----------------------------------------" << endl << endl;

    return 0;
}
