#include "TimeTask.h"


namespace sdds {

	TimeTask:: TimeTask() {

	}



	TimeTask& TimeTask::startClock()
	{
		m_startTime= std::chrono::steady_clock::now();
		return *this;
	}

	TimeTask& TimeTask::stopClock()
	{
		m_endTime= std::chrono::steady_clock::now();
		return *this;
	}


	TimeTask& TimeTask::addTask(const char* cstr)
	{
		m_task[m_noOfRecords].m_name = cstr;
		m_task[m_noOfRecords].m_unitOfName = "nanoseconds";
		m_task[m_noOfRecords].m_duration= std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_noOfRecords++;
		return *this;
	}



	std::ostream& operator << (std::ostream& os, const TimeTask& tiem) {
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