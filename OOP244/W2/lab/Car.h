/*
    ==================================================
    Workshop2 (Part-1):
    ==================================================

*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{

    struct Car
    {
        char* c_model; 
        char* c_plate; 
        int time;        
    };

    void VBPLE_Title();
    void initialize(int allocSize);
    void deallocate(Car& C);
    bool read(Car& C);
    void print(const Car& C);
    void record(const Car& C);
    void endOfDay();

} // namespace sdds
#endif
