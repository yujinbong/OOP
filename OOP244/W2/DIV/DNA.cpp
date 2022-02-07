
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "DNA.h"

using namespace std;

namespace sdds {
    const int maxdnachar = 2000;

    DNA* dna = nullptr;
    int numberofdna = 0;
    int allocationsize = 0;
    fstream fs;

    bool beginSearch(const char* filename) {

        fs.open(filename);
        if (fs.is_open())
        {
            cout << "DNA search program\n";
            numberofdna = 0;
            allocationsize = 0;
            dna = nullptr;
            return true;
        }
        return false;
    }

    bool read(const char* subDNA) {

        char cstring[maxdnachar];
        // reference ; https://stackoverflow.com/questions/28331017/rewind-an-ifstream-object-after-hitting-the-end-of-file
        fs.clear();
        fs.seekg(0);
        allocationsize = 0;
        while (!fs.eof())
        {
            fs.getline(cstring, maxdnachar);
            if (strstr(cstring, subDNA) != nullptr)
                allocationsize++;

        }
        if (allocationsize == 0)
            return false;

        dna = new DNA[allocationsize];

        fs.clear();
        fs.seekg(0);
        numberofdna = 0;
        while (!fs.eof())
        {
            fs.getline(cstring, maxdnachar);
            if (fs.eof())
                break;

            if (strstr(cstring, subDNA) != nullptr)
            {
                char* s_id = strtok(cstring, ",");
                dna[numberofdna].d_id = atoi(s_id);

                char* s_char = strtok(NULL, "\n");
                dna[numberofdna].d_char = new char[strlen(s_char) + 1];
                strcpy(dna[numberofdna].d_char, s_char);

                numberofdna++;
            }

        }

        return true;
    }


    void sort() {
        DNA temp;
        for (int i = 0; i < numberofdna - 1; i++)
        {
            for (int j = 0; j < numberofdna - i - 1; j++)
            {
                if (dna[j].d_id > dna[j + 1].d_id)
                {
                    temp.d_id = dna[j].d_id;
                    dna[j].d_id = dna[j + 1].d_id;
                    dna[j + 1].d_id = temp.d_id;

                    temp.d_char = dna[j].d_char;
                    dna[j].d_char = dna[j + 1].d_char;
                    dna[j + 1].d_char = temp.d_char;
                }
            }
        }
    }

    void displayMatches() {
        cout << numberofdna << " matches found:\n";
        for (int i = 0; i < numberofdna; i++)
        {
            cout << i + 1 << ") " << dna[i].d_id << ":\n";
            cout << dna[i].d_char << "\n";
            cout << "======================================================================\n";
        }

    }

    void endSearch()
    {
        fs.close();
        cout << "DNA Search Program Closed.\n\n";
    }

    void deallocate()
    {
        for (int i = 0; i < numberofdna; i++)
        {
            delete[] dna[i].d_char;
        }

        delete[] dna;
        dna = nullptr;
    }
}

