#pragma once
#ifndef SDDS_TIMETASK_H
#define SDDS_TIMETASK_H
#include <iostream>
#include <chrono>
#include <string>
const size_t max_object = 10;
namespace sdds {
	struct Event {
		std::string m_name{};
		std::string m_unitOfName{};
		std::chrono::steady_clock::duration m_duration{};
	};

	class TimeTask {
		size_t m_noOfRecords{};
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		Event m_task[max_object];

		
	    public:
			TimeTask();
			TimeTask& startClock();
			TimeTask& stopClock();
			TimeTask& addTask(const char* istr);

			friend std::ostream& operator << (std::ostream& os, const TimeTask& tiem);




	};


}



#endif // !SDDS_TIMETASK_H
