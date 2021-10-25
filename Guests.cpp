/*
    ==================================================
    Workshop #2 (Part-2):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/


#include <iostream>
#include "Guests.h"
using namespace std;

namespace sdds {

    void read(char *str, int len) {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }


    void read(PhoneNumber &thePhoneNumber) {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode;
        cin >> thePhoneNumber.m_number;

    }

//true일동안 계속 루프 반복됨
    bool read(Guest &theGuest) {
        cout << "Guest name: ";
        read(theGuest.m_name, sizeof(theGuest.m_name));
        if (theGuest.m_name[0] == '\0') {
            return false;
        }
        read(theGuest.m_phno);
        return true;
    }


    void print(const PhoneNumber &thePhoneNumber) {
        cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
    }


    void print(const Guest &theGuest) {
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
    }

    void print(const GuestList &theGuestList) {

        for (int i = 0; i < theGuestList.m_noOfGuests; ++i) {
            cout << i + 1 << "- ";
            print(theGuestList.m_gst[i]);
        }
        /*for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
            print(theGuestList.m_gst[i]);
        }*/

    }

    void addGuest(GuestList &theGuestList, const Guest &aGuest) {

        Guest *ptr = theGuestList.m_gst; //파라미터 두개!!
        theGuestList.m_gst = new Guest[theGuestList.m_noOfGuests + 1];
        for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
            theGuestList.m_gst[i] = ptr[i];
        }
        theGuestList.m_gst[theGuestList.m_noOfGuests++] = aGuest;

        delete[] ptr; //까머지마!!
    }

}


