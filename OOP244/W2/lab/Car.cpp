#define _CRT_SECURE_NO_WARNING
#include "Car.h"
#include "cStrTools.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


namespace sdds
{
    Car *car = nullptr;
    int allocationsize;
    int numberofcars;
    int carsize;

    void VBPLE_Title()
    {
        cout << "Vehicle Border Passing Log Entry" << endl;
        cout << "Enter the data in the following format:" << endl;
        cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
        cout << "Exit the program by entering the following:" << endl;
        cout << "X,<ENTER>" << endl;
    }
    void initialize(int allocSize)
    {
        numberofcars = 0;
        // sets the Car Array Size and the Allocation Size to the argument allocSize??
        carsize = allocationsize = allocSize;
        // dynamically allocates an array of Cars to the size of Allocation Size and keeps the address in The Car Pointer
        car = new Car[allocSize];
    }

    void deallocate(Car &C)
    {
        // Deletes the allocated memory pointed by the make and model pointer in the Car structure,
        delete[] C.c_model;
        delete[] C.c_plate;
        // then set it to nullptr.
        C.c_model=nullptr;
        C.c_plate=nullptr;
    }
    //(char *cString, unsigned int maxSize, char delimiter)
    bool read(Car &C)
    {
        const int max_size = 60;
        bool flag = false;
        char cString[max_size];
        read(cString, max_size,',');
        if(strcmp(cString,"X")!=0)
        {
            C.c_model=new char[strlen(cString)+1];
            strcpy(C.c_model,cString);

            read(cString, 8,',');
            C.c_plate=new char[strlen(cString)+1];
            strcpy(C.c_plate,cString);

            cin >> C.time;
            flag = true;
        }
        return flag;
    }
    void print(const Car &C)
    {
        cout << C.time << ": " << C.c_model << ","<< C.c_plate << endl;
    }
    void record(const Car &C)
    {
        if(numberofcars==allocationsize)
        {
            Car *tempcar=car;
            carsize=allocationsize+1;
            car=new Car[carsize];
            for(int i=0;i<numberofcars;i++)
            {
                car[i].c_model = tempcar[i].c_model;
                car[i].c_plate = tempcar[i].c_plate;
                car[i].time=tempcar[i].time;
            }
            allocationsize=carsize;
            delete [] tempcar;
            tempcar=nullptr;
        }
        car[numberofcars].c_model=C.c_model;
        car[numberofcars].c_plate=C.c_plate;
        car[numberofcars].time=C.time;
        numberofcars++;

/*  
        if(numberofcars<allocationsize)
        {
            car[numberofcars].c_model=new char[strlen(C.c_model)+1];
            car[numberofcars].c_plate=new char[strlen(C.c_plate)+1];
            
            strcpy(car[numberofcars].c_model,C.c_model);
            strcpy(car[numberofcars].c_plate,C.c_plate);
            car[numberofcars].time=C.time;
            
            numberofcars++;            

            delete [] C.c_model;
            delete [] C.c_plate;
            
        }
*/
    }
    void endOfDay()
    {
        for(int i=0;i<numberofcars;i++)
        {
            print(car[i]);
            deallocate(car[i]);
        }
        delete [] car;
        car=nullptr;
    }
}
