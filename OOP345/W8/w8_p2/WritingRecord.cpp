#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		EmployeeWage* rP;
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					rP = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						rP->rangeValidator();
					}
					catch (const string& msg) {
						delete rP;
						throw msg;
					}
					if (emp.luhn(emp[i].id)) {
						activeEmp += rP;
					}
					delete rP;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		unique_ptr<EmployeeWage> sP;
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					sP = make_unique<EmployeeWage>(emp[i].name, sal[j].salary);
					sP->rangeValidator();
					if (emp.luhn(emp[i].id)) {
						activeEmp += move(sP);
					}
				}
			}
		}
		return activeEmp;
		
	}
}