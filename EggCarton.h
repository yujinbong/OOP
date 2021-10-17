
/*===============================================
Workshop #5 (Part-1):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
//#define SDDS_SHOW_LIFETIME
//The EggCarton class encapsulates the size of the carton (i.e. the number of eggs it can hold),
//the number of eggs in the carton and whether the eggs are jumbo size or regular.
namespace sdds {
    const int RegularEggWeight = 50;
    const int JumboEggWeight = 75;
    //These wieghts are in Grams. (1000 Grams is one Kilo)
    class EggCarton {
        //instantiated using its size, number of eggs and if the eggs are jumbo size.
        //By default, the size of the carton is 6, the number of eggs is 0, and the eggs are not jumbo size.

        int m_size=0;
        int m_noOfEggs;
        bool m_jumbo; //설정해야할까?
        void setBroken();
    public:
        EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
        std::ostream& display(std::ostream& ostr) const;
        std::istream& read(std::istream& istr = std::cin);
        operator bool() const;
        operator int() const;
        operator double() const;
        //unary operator overloads
        EggCarton& operator--();//prefix
        EggCarton& operator++();
        EggCarton operator--(int); //postfix
        EggCarton operator++(int);
        //binary member
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
        //helper


    };
    int operator+(int left, const EggCarton& right);
    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
    std::istream& operator>>(std::istream& istr, EggCarton& right);


}
#endif