#include "PayrollManager.h"

void PayrollManager::addEmployee(Employee* e) {
    employees.push_back(e);
}

void PayrollManager::processPayroll() const {
    for (const auto& employee : employees) {
        employee->showInfo();
        std::cout << "Total Pay: " << employee->calculate() << "\n";
    }
}

PayrollManager::~PayrollManager() {
    for (auto& e : employees) {
        delete e;
    }
}