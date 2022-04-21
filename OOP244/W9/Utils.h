/*
Final project Milestone 3
 Filename: Date.cpp
name: Yujin Bong
student ID :147525208
SECTION : NDD
PROFESSOR : Arezoo.tony
Date: 2022/03/26
Author: Fardad Soleimanloo   2022-02-28
Revision History
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;

    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);
        int daysOfMon(int mon, int year) const;
        void testMode(bool testmode = true);
        void alocpy(char *&destination, const char *source);
        int getint(const char *prompt = nullptr);
        int getint(int min, int max, const char *prompt = nullptr, const char *errMsg = nullptr);
        double getdouble(const char *prompt);
        double getdouble(double min, double max, const char *prompt, const char *errMsg);
        int getFileLength(std::istream& is);
    };

    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
}

#endif // !SDDS_UTILS_H