/*
    ==================================================
    Workshop #2 (Part-2):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/
/////////////////////////////////////////////
#include <iostream>
#include "Guests.h"
using namespace std;
using namespace sdds;

int main() {
    bool done = false;
    char resturantName[51];
    Guest gst = { "", {0,0} };
    GuestList gl = { nullptr, 0 };
    PhoneNumber phno;
    cout << "Please enter the name of the restaurant: ";
    read(resturantName, 50);
    read(phno);
    cout << "Guest entry..." << endl;
    while (!done) {
        cout << "Enter guest information or Enter to exit:" << endl;
        if (read(gst)) {
            addGuest(gl, gst);
        }
        else {
            done = true;
        }
    }
    cout << endl << endl << resturantName << ", Phone Number: ";
    print(phno);
    cout << "**********************************************" << endl;
    cout << "Guestlist and their contacts: " << endl;
    print(gl);
    delete[] gl.m_gst;
}