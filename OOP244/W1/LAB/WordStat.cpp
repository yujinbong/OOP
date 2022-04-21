/*
    ==================================================
    Workshop #1 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NDD
*/

#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
    char filename[256];
    programTitle();
    cout << "Enter filename: ";
    cin >> filename;
    wordStats(filename);
    return 0;
}
