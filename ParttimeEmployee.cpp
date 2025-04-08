#include "ParttimeEmployee.h"
#include <iostream>

ParttimeEmployee::ParttimeEmployee(std::string name, int age, int id, int hours, double rate)
    : Employee(name, age, id), hoursWorked(hours), hourlyRate(rate) {}

double ParttimeEmployee::calculateSalary() const {
    return hoursWorked * hourlyRate;
}

void ParttimeEmployee::showInfo() const {
    Employee::showInfo();
    std::cout << "Hours Worked: " << hoursWorked << ", Hourly Rate: " << hourlyRate << std::endl;
}
