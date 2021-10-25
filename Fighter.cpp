/*
    ==================================================
    Workshop #2 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;
#include "Fighter.h"



namespace sdds {

    int index = -1;

    void fighter(char* name) {
        cout << "Enter Fighter Name: ";
        cin >> name;
    }

    void fighter(int& power) {
        cout << "Enter Fighter Power: ";
        cin >> power;
    }

    void display(const Fighter& myFighter) {
        cout << "Name: " << myFighter.name << "," << " Power: " << myFighter.power << endl;
    }

    void display(const Competition& mycompetition) {
        for (int i = 0; i < mycompetition.numfighters; i++) {
            display(mycompetition.fighters[i]);
        }
    }

    void addFighter(Competition& myCompetition) {
        Fighter *ptr;
        //Competition* ptr;?
        ptr = new Fighter[myCompetition.numfighters + 1];
        //loop 설정하기
      /*  for(int i = 0; i < myCompetition.numfighters; i++) {
            ptr[i] = myCompetition.fighters[i]; // check the list
        }*/
        int i = 0;
        while (i < myCompetition.numfighters) {
            strcpy(ptr[i].name, myCompetition.fighters[i].name);
             ptr[i].power = myCompetition.fighters[i].power;

            i++;
        }
        cout << "Information of the new fighter:" << endl;
        fighter(ptr[i].name);
        fighter(ptr[i].power);

        delete[] myCompetition.fighters;
        myCompetition.fighters = ptr;
        myCompetition.numfighters++;


    }

    void removeFighter(Competition& myCompetition, const Fighter& loserFighter) {

        Fighter* ptr = nullptr;
        ptr = new Fighter[myCompetition.numfighters - 1];

        findFighter(myCompetition, loserFighter);// find loserFIghter
        int a = 0, k = 0;
        while (k < myCompetition.numfighters) {
            if (k != index) {
                strcpy(ptr[a].name, myCompetition.fighters[k].name);
                ptr[a].power = myCompetition.fighters[k].power;

                a++;
            }
            k++;
        }

        delete[] myCompetition.fighters;
        myCompetition.fighters = ptr;
        myCompetition.numfighters--;// check\!!!
    }


    int findFighter(const Competition& mycompetition, const Fighter& theFighter) {

        for (int i = 0; i < mycompetition.numfighters; i++) {
            if (mycompetition.fighters[i].name == theFighter.name) {
                index = i;
                break;
            }

        }
        return index;
    }


    bool fight(const Fighter& f1, const Fighter& f2) {
        return (f1.power > f2.power); // 첫 번째 파이터가 두 번째 파이터보다 강하면 true를 반환하고 그렇지 않으면 false를 반환한다.
    }


    void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {

        cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;

        if (fight(f1, f2)) {
            cout << "    The winner => Name: " << f1.name << "," << " Power: " << f1.power << endl;
            removeFighter(mycompetition, f2);
        }
        else{
            cout << "    The winner => Name: " << f2.name << "," << " Power: " << f2.power << endl;
            removeFighter(mycompetition, f1);


        }
    }
}

