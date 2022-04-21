
#include <iostream>
#include <stdio.h>
#include "cStrTools.h"
using namespace std;

void phoneDir(const char* programTitle, const char* fileName) {
        cout << programTitle << "phone directory search\n";
        cout << "-------------------------------------------------------\n";

        while (1) {
                FILE *f = fopen(fileName, "r");

                if (!f) {
                        cout << fileName << " file not found!\n";
                        break;
                }
                else {

                        cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n>";
                        string partialName;
                        cin >> partialName;

                        if (partialName == "!")
                                break;

                        char name[50];
                        int area = 0, prefix = 0, number = 0;

                        while (1) {
                                // cout << "hey";

                                fscanf(f, "%[^\t]s", name);
                                getc(f);
                                fscanf(f, "%d", &area);
                                getc(f);
                                fscanf(f, "%d", &prefix);
                                getc(f);
                                fscanf(f, "%d", &number);
                                if (getc(f) == EOF)
                                        break;
                                
                                // cout << name << " " << area << "\n";
                                if (checkIfPresent(name, partialName))
                                        cout << name << ": (" << area << ") " << prefix << "-" << number << "\n";
                        }
                }
                fclose(f);
        }

        

        cout << "Thank you for using " << programTitle << " directory.\n";

}
