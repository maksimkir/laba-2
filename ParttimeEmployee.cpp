#include "ParttimeEmployee.h"
#include <iostream>

using namespace std;

ParttimeEmployee::ParttimeEmployee(int id, int hours, double rate)
    : Employee(id, 0), hoursWorked(hours), hourlyRate(rate) {}

void ParttimeEmployee::showInfo() const {
    cout << "Part-Time Employee ID: " << id
         << "\nHours Worked: " << hoursWorked
         << "\nHourly Rate: " << hourlyRate << endl;
}

double ParttimeEmployee::calculate() const {
    return hoursWorked * hourlyRate;
}
