#ifndef PAYROLLMANAGER_H
#define PAYROLLMANAGER_H

#include <vector>
#include <iostream>
#include "Employee.h"

class PayrollManager {
private:
    std::vector<Employee*> employees;

public:
    void addEmployee(Employee* e);
    void processPayroll() const;
    ~PayrollManager();
};

#endif