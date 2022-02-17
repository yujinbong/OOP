
/* ------------------------------------------------------
Workshop 4 part 1
Student Name : Yujin Bong
Email : ybong@myseneca.ca
Date:Feb.8
Student ID : 147525208
Section : NDD
Author: Asad Norouzi  Fall of 2021
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials   Date           Reason
F.S.	     04/02/2022     Added covered topics and simplifed.
-----------------------------------------------------------*/

#ifndef W4P1_CARINVENTORY_H
#define W4P1_CARINVENTORY_H

namespace sdds
{
    class CarInventory {

    private:
        char* m_type=nullptr;
        char* m_brand=nullptr;
        char* m_model=nullptr;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();


    public :
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year=2022, int code=100, double price=1);
         ~CarInventory();

        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };

    bool find_similar(CarInventory car[], const int num_cars);
}
#endif
