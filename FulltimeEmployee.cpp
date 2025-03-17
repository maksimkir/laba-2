#include "FulltimeEmployee.h"
#include <iostream>

using namespace std;

FulltimeEmployee::FulltimeEmployee(int id, double salary, double bonus)
    : Employee(id, salary), bonus(bonus) {}

void FulltimeEmployee::showInfo() const {
    cout << "Full-Time Employee: " << id
         << "\nSalary: " << salary
         << "\nBonus: " << bonus << endl;
}

double FulltimeEmployee::calculate() const {
    return salary + bonus;
}