/*
Final project Milestone 1
name: Yujin Bong
student ID :147525208
SECTION : NDD
PROFESSOR : Arezoo.tony
Date: 2022/03/13
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
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);

        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2021)
        int daysOfMon(int mon, int year) const;

        // Puts the system date in test mode, where getSystemDate() function will return 2022, 03, 31
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);

        void alocpy(char *&destination, const char *source);

        int getint(const char *prompt = nullptr);

        int getint(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
    };

    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
}

#endif // !SDDS_UTILS_H
