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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Robot.h"

using namespace std;

namespace sdds {


    Robot::Robot() {
        setSafeEmpty();
    }

    Robot::Robot(const char *name, const char *location, double weight, double width, double height, double speed,
                 bool deployed) {
        m_name = nullptr;
        m_location = nullptr;
        set(name, location, weight, width, height, speed, deployed);
    }

    //The destructor must handle any potential memory leak
    Robot::~Robot() {
        delete[] m_location;
        delete[] m_name;
    }

    void Robot::setSafeEmpty() {
        delete[] m_location;
        delete[] m_name;
        m_location = nullptr;
        m_name = nullptr;
        m_weight = 0;
        m_width = 0;
        m_height = 0;
        m_speed = 0;
        m_deployed = false;
    }

    Robot &Robot::set(const char *name, const char *location, double weight, double width, double height, double speed,
                      bool deploy) {
        if (name != nullptr && strlen(name) > 0 && location != nullptr && strlen(location) > 0 && weight > 0.00 &&
            width > 0.00 && height > 0.00 && speed > 0.00) {

            delete[] m_name;
            delete[] m_location;

            m_name = new char[strlen(name) + 1];
            m_location = new char[strlen(location) + 1];

            strcpy(m_name, name);
            strcpy(m_location, location);
            m_weight = weight;
            m_width = width;
            m_height = height;
            m_speed = speed;
            m_deployed = deploy;

        } else {
            setSafeEmpty();
        }
        return *this;
    }

/* m_weight = weight;
            m_width = width;
            m_height = height;
            m_speed = speed;
            m_deployed = deploy;*/
    Robot &Robot::setLocation(const char *location) {
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
        return *this;
    }

    const char *Robot::getName() const {

        return m_name;
    };

    const char *Robot::getLocation() const {
        return m_location;
    };


    Robot &Robot::setDeployed(bool deployed) {
        m_deployed = deployed;
        return *this;
    }

    bool Robot::isDeployed() const {
        return m_deployed;
    }

    bool Robot::isValid() const {
        return m_name != nullptr && m_location != nullptr&& m_width >=0 && m_weight>=0 && m_speed;

    }

    double Robot::getSpeed() const {
        return m_speed;
    };


    void Robot::display() const {
        cout << "| ";
        cout.setf(ios::left);
        cout.width(10);
        cout << m_name << " | ";
        cout.width(15);
        cout << m_location << " | ";
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout.width(6);
        cout << setprecision(1) << m_weight << " | ";
        cout.width(6);
        cout << setprecision(1) << m_width << " | ";
        cout.width(6);
        cout << setprecision(1) << m_height << " | ";
        cout.width(6);
        cout << setprecision(1) << m_speed << " | ";
        cout.width(8);
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        if (isDeployed())
            cout << "YES" << " |" << endl;
        else
            cout << "NO" << " |" << endl;
        cout.unsetf(ios::left);

    }

    int conrtolRooomReport(const Robot robot[], int num_robots) {
        int i=0;
        cout << "                        ------ Robot Control Room -----" << endl;
        cout << "                    ---------------------------------------" << endl;
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
        cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
        for(i=0; i<num_robots; i++){

        if (robot[i].isValid()) {
         robot[i].display();
            }
        else {
            return i;
        }



        } if(i==num_robots){

            cout << "|=============================================================================|"<<endl;
            cout<<"| SUMMARY:                                                                    |"<<endl;
            cout <<"| 3  robots are deployed.                                                     |"  << endl;
            cout <<"| The fastest robot is:                                                       |"<<endl;
            cout <<"| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |"<<endl;
            cout <<"|------------+-----------------+--------+--------+--------+--------+----------|"<<endl;
          for(i=0; i<num_robots-1; ++i) {
          int small=i;
          for(int j=i+1; j <num_robots; ++j){
              if(robot[small].getSpeed()<robot[j].getSpeed() ){
                  small=j;
              }
          }


              robot[small].display();
          cout << "|=============================================================================|"<<endl;
          break;
          }
        }

        return -1;
    }


}
