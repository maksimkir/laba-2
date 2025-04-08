#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class ParttimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    ParttimeEmployee(std::string name, int age, int id, int hours, double rate);
    double calculateSalary() const override;
    void showInfo() const override;
};

#endif