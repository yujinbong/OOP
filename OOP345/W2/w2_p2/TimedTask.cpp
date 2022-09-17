// Workshop 2 - Copy and Move Semantics
// 2021/11/28 - Mufleh Al-Shatnawi
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "TimedTask.h"
#include <iomanip>


namespace sdds {

	TimedTask::TimedTask()
	{
	}

	TimedTask& TimedTask::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
		return *this;
	}

	TimedTask& TimedTask::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
		return *this;
	}

	TimedTask& TimedTask::addTask(const char* cstr)
	{
		m_task[m_noOfRecords].taskName = cstr;
		m_task[m_noOfRecords].unitTime = "nanoseconds";
		m_task[m_noOfRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_noOfRecords++;
		return *this;
	}


	std::ostream& operator<<(std::ostream& os, const TimedTask& time)
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << "Execution Times:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < (int)time.m_noOfRecords; i++) {
			std::cout << std::setw(21) << std::left << time.m_task[i].taskName;
			std::cout << std::setw(13) << std::right << time.m_task[i].duration.count() << ' ';
			std::cout << time.m_task[i].unitTime << std::endl;
		}
		std::cout << "--------------------------" << std::endl;

		return os;
	}


}
