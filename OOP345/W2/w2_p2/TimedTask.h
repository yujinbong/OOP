// Workshop 2 - Copy and Move Semantics
// 2021/11/28 - Mufleh Al-Shatnawi
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef  SDDS_TIMEDTASK_H
#define  SDDS_TIMEDTASK_H
#include <iostream>
#include <cstring>
#include <chrono>
#include <ratio>
#include <thread>
const size_t MaxNumberOfEvent = 10;

namespace sdds {
	struct Event { 
		std::string taskName{};
		std::string unitTime{};
		std::chrono::steady_clock::duration duration{};
	
	};
	class TimedTask {
		size_t m_noOfRecords{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		Event m_task[MaxNumberOfEvent];

	public:
		//part1->동적할당 할 필요 없음으로 Roul of 3 X
		TimedTask();
		TimedTask& startClock();
		TimedTask& stopClock();
		TimedTask& addTask(const char* istr);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& time);

	};


}
#endif
