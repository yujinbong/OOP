/* ------------------------------------------------------
Workshop 4 part 2
Student Name : Yujin Bong
Student ID : 147525208
Section : NDD
Professor : Arezoo Tony
 Date : Feb.
Module: N/A
Filename: main.cpp
Version 1.0
Author: Asad Norouzi  Fall of 2021
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials   Date           Reason
F.S.	     04/02/2022     Added covered topics and simplifed.
-----------------------------------------------------------*/

#ifndef W4P2_ROBOT_H
#define W4P2_ROBOT_H

namespace sdds {

    class Robot {

    private:
        char *m_name = nullptr;
        char *m_location = nullptr;
        double m_weight;
        double m_width;
        double m_height;
        double m_speed;
        bool m_deployed;



    public:
        Robot();  //Constructors
        Robot(const char *name, const char *location, double weight, double width, double height, double speed,
              bool deployed);
        ~Robot(); //Destructor
        //queries
        Robot& set(const char *name, const char *location, double weight, double width, double height, double speed,
                   bool deployed);
        Robot& setLocation(const char *location);
        Robot& setDeployed(bool deployed) ;
        void setSafeEmpty();
        const char *getName() const;
        const char *getLocation() const;
        bool isDeployed() const;
        bool isValid()const;
        double getSpeed() const;
        void display() const;
    };

    int conrtolRooomReport(const Robot robot[], int num_robots); //global function



}
#endif //W4P2_ROBOT_H












